if [ -f "$1" ]; then
    size=`stat -f%z $1`
    echo "$1 $size"
    exit 0
fi
if [ -d "$1" ]; then
    for file in "$1"/*
    do
        size=`stat -f%z $file`
        echo "$file $size"
    done
fi
