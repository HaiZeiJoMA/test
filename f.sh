#!/bin/bash

flist=0
dlist=0
file=$1
for i in `find $file -type f`; do
    flist=$(($flist + 1))    
done

for i in `find $file -type d`; do
    dlist=$(($dlist + 1))    
done

echo "有文件数量： $flist"
echo "有目录数量： $dlist"


