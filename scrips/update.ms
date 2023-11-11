cd $CONPILE_DIR
sleep 1
git pull --all
make re
cd -
sleep 1
echo 'the shell whill close , re open it to use it'
sleep 2
exit