echo file a ?
test -e a
ms -l 'echo yes' 'ms -j 5'
ms -j 6
echo a > a
ms -j 0
exit 0
