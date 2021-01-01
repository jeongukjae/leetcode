# 192. Word Frequency
cat words.txt | \
    tr '[:space:]' '[\n*]' | \
    sed -r '/^\s*$/d' | \
    sort | \
    uniq -c | \
    sort --reverse | \
    awk '{print $2 " " $1}'
