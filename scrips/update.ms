cd $CONPILE_DIR
sleep 1
git pull --all
make re
echo -n 'back to '
cd -
sleep 1
echo 'close and re-open to use the new update'