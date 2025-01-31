for i in {1..9}
do
    echo "$1_$i.in"
    ./a.out <"$1_$i.in" >tt
    diff "$1_$i.out" tt -Z
done
rm tt
