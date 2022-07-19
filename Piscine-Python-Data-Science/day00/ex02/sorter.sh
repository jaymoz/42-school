head -n 1 "../ex01/hh.csv" > "hh_sorted.csv"
tail -n +2 "../ex01/hh.csv" | sort -t "," -k 2 -k 1n >> "hh_sorted.csv"