filename=0192____.txt

cat $filename | tr -s ' ' '\n'|sort|uniq -c|sort -r|awk '{print $2 " " $1}'

# tr -s ' ' '\n':           将连续的一个或多个空格替换为换行
# sort | uniq:              对结果进行排序并统计不同单词的数目
# sort -r:                  逆序sort
# awk '{print $2 "" $1}':   格式化输出
