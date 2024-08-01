fn main() {
    let (n, t) = double_cin();
    let vec: Vec<i128> = vec_cin();
    // vec.sort_by(|a, b| b.cmp(a));
    let mut sum: i128 = vec.iter().sum();
    let max: i128 = n as i128 * t as i128;
    
    if sum > max {
        println!("-1");
        return;
    }

    let mut _cnt:i128 = 0;
    // let remaining_t = t;
    let mut excess_h2o = 0;
    for i in 0..n
    {
        if excess_h2o<0
        {
            println!("-1");
            return();
        }
        if (vec[i]-excess_h2o)>0
        {
            if (vec[i]-excess_h2o-t)>0
            {
                println!("-1");
                return ();
            }
            _cnt +=1;
            excess_h2o = t-(vec[i]-excess_h2o);
        }
        else 
        {
            if sum >excess_h2o
            {
                excess_h2o +=t;
                _cnt +=1;
            }
            excess_h2o =excess_h2o-vec[i];
        }
        sum -= vec[i];
    }
    // if vec[vec.len()-1]!=0
    // {
    //     println!("-1");
    //     return ();
    // }

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
