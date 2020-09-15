if [ $1 == "-c" ]; then
    tar -cf "$2.tar" $3
    exit 0
fi
if [ $1 == "-e" ]; then
    tar -xf $2
fi