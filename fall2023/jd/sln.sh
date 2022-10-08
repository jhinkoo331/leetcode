# desc: sale.txt中记录了不同水果的销量和售价, 第二列是销量, 第三列是售价
# 要求: 过滤出销量大于10的水果

filename=sale.txt

awk '$2>10' $filename # $2表示第二列, awk对列是1-indexing的
