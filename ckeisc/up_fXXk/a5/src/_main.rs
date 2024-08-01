fn main() {
    let (n,t) = double_cin();
    let mut vec:Vec<i128> =vec_cin();
    let max:i128 = (n*t).into();
    let sum:i128 = sum(&vec);
    let mut _cnt = 0;
    if sum<=max
    {
        for i in 0..n
        {
            let mut _t = t;
            if vec[i as usize]>t
            {
                print!("{}",-1);
                return ();
            }
            if !is_not_null(&vec)
            {
                _cnt += 1;
                let mut j = i;
                while 
                {
                    if _t>vec[j as usize]
                    {
                        _t -=vec[j as usize];
                        vec[j as usize]=0;
                    }
                    else
                    {
                        vec[j as usize] -=_t;
                        _t = 0;
                    }
                    j+=1;
                    _t>0 && j<n
                }{}
            }
        }
        for v in &vec
        {
            if *v!=0
            {
                print!("{}",-1);
                return ();
            }
        }
        print!("{}",_cnt);
    }
    else 
    {
        print!("{}",-1);
    }
}

fn double_cin()->(i128,i128)
{
    let mut input_str = String::new();
    std::io::stdin().read_line(&mut input_str).expect("");
    let mut input_parts = input_str.trim().split_whitespace();
    let first = input_parts.next().expect("").trim().parse().expect("");
    let sec = input_parts.next().expect("").trim().parse().expect("");
    (first,sec)

}

fn vec_cin()->Vec<i128>
{
    let mut input_str = String::new();
    std::io::stdin().read_line(&mut input_str).expect("");
    //collect:turn a iterator into a vector
    let vec:Vec<i128> = input_str.trim().split_whitespace().map(|word| word.trim().parse().expect("")).collect();
    vec
}

fn sum(vec:&Vec<i128>) ->i128
{
    let mut sum:i128 = 0;
    for v in vec
    {
        sum += *v as i128;
    }
    sum
}

fn is_not_null(vec:&Vec<i128>) -> bool
{
    for v in vec
    {
        if *v != 0 
        {
            return false;
        }
    }
    return true;
}