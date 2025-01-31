for i in {1..9}
do
    echo "$1_$i.in"
    ./"$2" <"$1_$i.in" >"$1_$i.out"
done
