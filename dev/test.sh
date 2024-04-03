#!/bin/bash

sys= uname -s
test $sys "Darwin"
if [ $? != 0 ]
then
  slow=0
  L="\""
else
  slow=1
  L="'"
fi

# color
RED=\\x1B[31m
GRN=\\x1B[32m
YEL=\\x1B[33m
BLU=\\x1B[34m
MAG=\\x1B[35m
CYN=\\x1B[36m
WHT=\\x1B[37m
RESET=\\x1B[0m

# -- -- -- var
outfileval="$PWD/out/val.log"
val="valgrind --trace-children=yes --track-fds=yes --suppressions=/tmp/supp.txt --log-file=$outfileval"

## test
testlist=(
  'ls'
  'echo'
  'echo -n'
  'echo $PWD'
  'cd .. ; ls'
  '""'
  "''"
  "ls -la"
  "|"
  "hello\"\"gorge"
  "echo a | echo"
  "echo   | echo"
  "echo a | echo a"
  "echo   | echo a"
  "a ; echo $?"
  "ms -i"
  "echo a a a | cat | wc"
  "env | grep 'LOGNAME'"
  "pwd | cut -c5- | wc "
  "$ $\?"
  "echo || echo no"
  "echo && echo yes"
  "\""
  "'"
  "ls < a"
  "echo < a"
  "echo > a"
  "ls > a"
  "cat < a"
  "< b cat -e"
  "< a cat -e"
  "< b < a cat"
  "?"
  "<"
  "<<"
  "<<"
  "<<<"
  "<< <"
  ">"
  ">>"
  ">>>"
  ">> >"
  "||"
  "pwd || echo a"
  "pwd |  echo b"
  "$;"
  "\$?;ls"
  "\$?;pwd"
  "\$?;<a cat -e "
  "ls;ls;ls"
  "ls | ls |ls| ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls | echo"
)

i=${#testlist[@]}
j=0
di=0

function runTest() {
  printf "$YEL --- --- ---$RESET\n"
  bash           -c "${testlist[$j]}" > out/out_ba
  bacode=$?
  rm -fr a b
  $val minishell -c "${testlist[$j]}" > out/out_ms
  mscode=$?
  err=0
  if [ $bacode != $mscode ];
  then
    printf \%s\ "Error: return value\n shell give $GRN$bacode$RESET ms give $RED$mscode$RESET \n"
  fi
  str=$(grep  "definitely lost" $outfileval | cut -c15-)
  test "$str" = 'definitely lost: 0 bytes in 0 blocks'
  ((err+=$?))
  str=$(grep  "indirectly lost" $outfileval | cut -c15-)
  test "$str" = 'indirectly lost: 0 bytes in 0 blocks'
  ((err+=$?))
  str=$(grep  "possibly lost" $outfileval | cut -c15-)
  test "$str" = '  possibly lost: 0 bytes in 0 blocks'
  ((err+=$?))
  str=$(grep  "still reachable" $outfileval | cut -c15-)
  test "$str" = 'still reachable: 0 bytes in 0 blocks'
  ((err+=$?))
  if [ $err != 0 ]
  then
    grep  "definitely lost" $outfileval | cut -c15-
    grep  "indirectly lost" $outfileval | cut -c15-
    grep  "possibly lost"   $outfileval | cut -c15-
    grep  "still reachable" $outfileval | cut -c15-
  fi
  rm -f out/val.log
  diff  out/out_ba out/out_ms >> diff.txt
}

# start of scrip
rm -r diff.txt
make -C .. re
make -C .. cp
echo "making dir"
mkdir -p out

while [ $j -lt $i ]
do
  runTest
  di=$?
  if [ $di != 0 ]
  then
    printf \%s\ "❌$RED ${testlist[$j]} $RESET\n"
    printf \%s\ "❌${testlist[$j]}\n" >> diff.txt
    echo 'ms >'
    cat -be out/out_ms
    echo 'ms <'
    echo 'ba >'
    cat -be out/out_ba
    echo 'ba <'
  else
    printf \%s\ "✅$GRN ${testlist[$j]} $RESET\n"
  fi
  j=$((j + 1))
  if [ $slow == 1 ]
  then
    echo '- - - - -'
  fi
  sleep 0.3
done
read -p "rm file? (Y/N): " confirm && [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]] || exit 0
make -C .. clean
rm out/out_ms out/out_ba
rm -fr out
rm diff.txt
make -C .. fclean
