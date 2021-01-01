# 194. Transpose File
file=file.txt
ncols=`head -n1 $file | wc -w`
for i in `seq 1 $ncols`; do
    cat $file | awk "{ printf \$$i \" \" }" | xargs
done
