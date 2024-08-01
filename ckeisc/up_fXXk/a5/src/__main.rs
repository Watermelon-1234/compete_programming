fn main() {
    let (n, t) = double_cin();
    let mut vec: Vec<i128> = vec_cin();
    // vec.sort_by(|a, b| b.cmp(a));
    let mut sum: i128 = vec.iter().sum();
    let max: i128 = n as i128 * t as i128;
    
    if sum > max {
        println!("-1");
        return;
    }

    let mut _cnt:i128 = 0;
    for i in 0..n
    {
        if sum> 0
        {
            let mut _t = t;
            if vec[i]>t
            {
                print!("{}",-1);
                return ();
            }_cnt += 1;
            let mut j = i;
            while 
            {
                if _t>vec[j]
                {
                    _t -=vec[j];
                    sum -=vec[j];
                    vec[j]=0;
                }
                else
                {
                    vec[j] -=_t;
                    sum -= _t;
                    _t = 0;
                }
                j+=1;
                _t>0 && j<n
            }{}
        }
    }
    if sum!=0
    {
        println!("-1");
        return ();
    }

    println!("{}", _cnt);
}

fn double_cin() -> (usize, i128) {
    let mut input_str = String::new();
    std::io::stdin().read_line(&mut input_str).expect("");
    let mut input_parts = input_str.trim().split_whitespace();
    let n = input_parts.next().expect("").trim().parse().expect("");
    let t = input_parts.next().expect("").trim().parse().expect("");
    (n, t)
}

fn vec_cin() -> Vec<i128> {
    let mut input_str = String::new();
    std::io::stdin().read_line(&mut input_str).expect("");
    input_str.trim().split_whitespace().map(|word| word.trim().parse().expect("")).collect()
}
