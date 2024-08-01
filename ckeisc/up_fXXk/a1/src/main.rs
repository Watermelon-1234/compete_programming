use std::io;
use std::i128;
fn main() {
    let mut _n: String = String::new();
    let mut _sum:i128 = 0;
    io::stdin().read_line(&mut _n).expect("");
    let _n:i128 = _n.trim().parse().expect("");
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("");
    for c in input.chars() {
        match c{
            '_'=>_sum += 30,
            '-'=>_sum += 70,
            '*'=>_sum += 500,
            _  =>continue,
        }
    }
    // let _sum:f64 = _sum as f64 /_n as f64;
    _sum = _sum/_n;
    if _sum<=33
    {
        println!("tsai");
    }
    else if _sum >=67
    {
        println!("niubee");
    }
    else 
    {
        println!("have toppings");
    }
}
