#[warn(unused_assignments)]
const PI:f64 = 3.141592653589793;
const SQRT_3:f64 = 1.732050807568877;

fn main() {
    let (c,w,h) = trible_cin();
    let mut vec:Vec<(i32,i32)> = Vec::new();
    let max_area:f64 =(w as f64)*(h as f64);
    let mut area = 0.0;
    let mut quarter_circle = 0.0;
    let mut square = 0;
    let mut fuck = 0.0;
    for _i in 0..c
    {
        let v:(i32,i32) =double_cin(); 
        // quarter_circle +=4.0;
        if vec.contains(&v)//d==0
        {
            continue;
        }
        for  dx in [-1,1]
        {
            for dy in [-1,1]
            {
                if !out_of_range(v.0+dx,v.1+dy,w,h)
                {
                    if vec.contains(&(v.0+dx,v.1+dy))
                    {
                        quarter_circle -= 1.0;
                        square +=1;
                    }
                    else 
                    {
                        if vec.contains(&(v.0,v.1+dy))
                        {
                            fuck += 1.0;
                        }
                        if vec.contains(&(v.0+dx,v.1))
                        {
                            fuck += 1.0;
                        }
                    }
                }
                
            }
        }
        vec.push(v);
    }
    area =quarter_circle*PI/4.0+square as f64+fuck*( PI/6.0 +SQRT_3/4.0);
    println!("{:.}",area/max_area)
}

fn double_cin()->(i32,i32)
{
    let mut input_str = String::new();
    std::io::stdin().read_line(&mut input_str).expect("");
    let mut input_parts = input_str.trim().split_whitespace();
    let first = input_parts.next().expect("").trim().parse().expect("");
    let sec = input_parts.next().expect("").trim().parse().expect("");
    (first,sec)

}

fn trible_cin()->(i32,i32,i32)
{
    let mut input_str = String::new();
    std::io::stdin().read_line(&mut input_str).expect("");
    let mut input_parts = input_str.trim().split_whitespace();
    let first = input_parts.next().expect("").trim().parse().expect("");
    let sec = input_parts.next().expect("").trim().parse().expect("");
    let third = input_parts.next().expect("").trim().parse().expect("");
    (first,sec,third)

}

fn out_of_range(x:i32,y:i32,w:i32,h:i32) ->bool
{
    if x>w ||x<0 || y>h ||y<0
    {
        return true;
    }
    return false;
}

// fn distance(v1:&(i32,i32), v2:&(i32,i32)) ->f64
// {
//     let x = abs(v1.0 - v2.0) as f64;
//     let y = abs(v1.1 - v2.1) as f64;
//     return (x*x + y*y).sqrt();
// }