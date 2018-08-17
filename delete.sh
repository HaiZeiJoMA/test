#!/bin/bash
if [ ! -d ~/.trash ]
then
	mkdir ~/.trash 
fi     
if [ $# == 0 ]
then
	echo "格式错误"    
elif [ $1 == "-r" ]    
then
    	echo "您所想删除的文件目录是："
for ((i = 2; i<=$#; i++)); do    
	echo ${!i}    
done

	echo -n "确定删除该目录中的所有文件嘛？ [Y/n]:"
	read reply

	if [ "$reply" != "n" ] && [ "$reply" != "N" ]
    then
        for ((i=2; i<=$#; i++)) 
        do
            file=${!i}
			if [ -d $file ]
			then
				cp -ri "$file" ~/.trash/
                rm -rf "$file"
            elif [ -f "$file" ]
            then
	            cp  "$file" ~/.trash/
                rm  "$file"
			fi
		done
	else
		echo "不进行删除"
    fi
elif [ $1 == "-rf" ]
then
    for ((i=2; i<=$#; i++)) 
    do
        file=${!i}
		if [ -d $file ]
		then
			cp -ri "$file" ~/.trash/
            rm -rf "$file"
        elif [ -f "$file" ]
        then
	        cp  "$file" ~/.trash/
            rm  "$file"
		fi
	done
else 
	echo "您所想删除的文件是："
	echo $@

	echo -n "确定删除该文件嘛？ [Y/n]:"
	read reply

	if [ "$reply" != "n" ] && [ "$reply" != "N" ]
	then
		for file in "$@"  
		do
			if [ -f "$file" ]
			then
				cp -ri "$file" ~/.trash/
                rm "$file"
			else
				echo "$file: 该文件为目录，若想删除请使用delete -r进行尝试"
			fi
		done
	else
		echo "不进行删除"
	fi
fi
