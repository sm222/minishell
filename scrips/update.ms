cd $CONPILE_DIR
sleep 1
git pull --all
make re
cd -
sleep 1
echo 'close and re-open to use the new update'