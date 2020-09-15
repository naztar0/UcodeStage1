while IPS= read -r line || [ -n "$line" ]; do
    if [[ $line =~ ^[rR][eE][dD][pP][iI][lL][lL].+ ]]; then
        echo $line
    fi
done < $1