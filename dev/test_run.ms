#this scrips is use to test a minishell
#you can add test 
#and pls help me to make it better

echo made by @sm222

#https://github.com/sm222

mkdir -p output
#clean file 
echo 'test file' > output/msout
echo 'test file' > output/bashout

echo test 0 
bash -c 'echo $?' >> output/bashout
minishell -c 'echo $?' >> output/msout
#
sleep 1
echo test 1 ls
minishell -c 'ls > output/ms0'
bash -c 'ls > output/ba0'
diff output/ms0 output/ba0 || echo 'fail'
sleep 1
#
echo test 2 /bin/ls ; echo
minishell -c '/bin/ls > output/ms0'
bash -c 'ls > output/ba0'
diff output/ms0 output/ba0 || echo 'fail'
sleep 1
#
echo test '|'
minishell -c '|'
bash -c '|'
#
echo
sleep 1
echo test '\tls'
minishell -c '	ls'
bash -c      '	ls'
#
echo test 'echo a b c | wc | cat -e' ; echo
minishell -c 'echo a b c | wc | cat -e'
bash -c 'echo a b c | wc | cat -e'
echo ; sleep 1
#
echo test '<'
minishell -c '<'
bash -c '<'
#
echo test '<<'
minishell -c '<<'
bash -c '<<'