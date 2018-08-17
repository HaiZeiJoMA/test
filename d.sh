#!/bin/bash
maxString=""
maxFilePath=""
maxLength=0
function getLongestString() {
    file=$1

    if [[ ! -n  $file ]]; then
        file=.
    fi
    for i in `find $file -type f -size -1M`; do
        filePath=$i
        if [[ -f $filePath ]]; then
            for j in `cat $filePath`; do
                if [[ ${#j} -gt $maxLength ]]; then
                    maxString=$j
                    maxFilePath=$filePath
                    maxLength=${#j}
                fi
            done
        fi
    done
    if [[ -n $maxFilePath ]]; then 
        echo 最长的字符串为： 
        echo $maxString
        echo 
        echo 该文件名为：
        echo $maxFilePath
        echo
        echo 该字符串长度为：
        echo $maxLength
    fi
}
getLongestString $1
