filename=0195____.txt
line=4

#awk -vline=$line NR==line $filename

# -vline=$line      创建变量line, 赋值$line
# NR==line          NR是内置变量, 表示以读出的行数, 1-indexed



# perf: 0ms, 90%
tail -n +$line $filename | head -n 1

