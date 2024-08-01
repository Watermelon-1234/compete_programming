#![allow(non_snake_case)]
// use std::{intrinsics::{powf64, powif64}, io};
use std::io;
fn main() {
    let n = cin();
    let (pa,mut xa):(f64,f64) = double_cin();
    let (pb,mut xb):(f64,f64) = double_cin();
    // let mut current_pressure = 1.0;


    for _i in 0..(n as i32)
    {
        let current_pressure =pa*xa+pb*xb;
        round_and_println(current_pressure);
        xa = (pa*xa)/current_pressure;
        xb = (pb*xb)/current_pressure;
    }
    // for _i in 0..(n as i32) {
    //     current_pressure = (xa*pow(pa, _i+1 )+xb*pow(pb, _i+1))/current_pressure;
    //     round_and_println(current_pressure);
    // }
    fn cin()->f64
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("");
        let input:f64 = input.trim().parse().expect("");
        input
    }

    fn double_cin()->(f64,f64)
    {
        let mut input_str = String::new();
        std::io::stdin().read_line(&mut input_str).expect("");
        let mut input_parts = input_str.trim().split_whitespace();
        let first = input_parts.next().expect("").trim().parse().expect("");
        let sec = input_parts.next().expect("").trim().parse().expect("");
        (first,sec)

    }
}

// fn pow(x:f64, y:i32) -> f64
// {
//     if y==1
//     {
//         return x;
//     }
//     else 
//     {
//         return pow(x,y-1)*x;
//     }
// }

fn round_and_println(x:f64)
{
    let x = (x*100.0).round()/100.0;
    println!("{:.2}", x);
}
