#!bin/bash

sys= uname -s
test $sys "Darwin"
if [ $? != 0 ];
then
  L="\""
else
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
val="valgrind --leak-check=full --trace-children=yes --track-fds=yes --suppressions=/tmp/supp.txt --log-file=$outfileval"

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
  "echo | echo"
  "a ; echo $?"
  "ms -i"
)

i=${#testlist[@]}
j=0
di=0

function runTest() {
  echo '--- --- ---'
  $val minishell -c "${testlist[$j]}" > out/out_ms
  mscode=$?
  bash           -c "${testlist[$j]}" > out/out_ba
  bacode=$?
  if [ $bacode != $mscode ];
  then
    printf \%s\ "Error: return value\n shell give $GRN$bacode$RESET ms give $RED$mscode$RESET \n"
  fi
  grep  "definitely lost" $outfileval | cut -c15-
  grep  "indirectly lost" $outfileval | cut -c15-
  grep  "possibly lost"   $outfileval | cut -c15-
  grep  "still reachable" $outfileval | cut -c15-
  rm -f out/val.log
  diff  out/out_ba out/out_ms >> diff.txt
}


rm -r diff.txt
while [ $j -lt $i ]
do
  runTest
  di=$?
  if [ $di != 0 ]
  then
    printf \%s\ "❌$RED ${testlist[$j]} $RESET\n"
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
  #sleep 1
done
rm out/out_ms out/out_ba