#[warn(unused_assignments)]
const PI:f64 = 3.141592653589793;
const SQRT_3:f64 = 1.732050807568877;

fn main() {
    let (c,mut w,mut h) = trible_cin();
    let max_area:f64 =(w as f64)*(h as f64);
    h+=1;
    w+=1;
    let mut vec:Vec<Vec<Vec<i32>>> = vec![vec![Vec::new();(210) as usize];(210) as usize];
    let mut area = 0.0;
    for _i in 0..c
    {
        let v:(i32,i32) =double_cin(); 
        if (v.0 >=0 && v.0 <=w) && (v.1 >= 0 && v.1 <=h)
        {
            if !vec[v.0 as usize][v.1 as usize].contains(&3)
            {
                vec[v.0 as usize][v.1 as usize].push(3);
            }
            // println!("3");
        }
        if (v.0 >= 0 && v.0<= w) && (v.1 >=1 && v.1<= h+1)
        {
            if !vec[v.0 as usize][((v.1)-1) as usize].contains(&2)
            {
                vec[v.0 as usize][((v.1)-1) as usize].push(2);
            }
            // println!("2");
        }
        if (v.0>=1 && v.0 <= w+1) && (v.1 >= 0 && v.1<= h)
        {
            if !vec[((v.0)-1) as usize][v.1 as usize].contains(&4)
            {
                vec[((v.0)-1) as usize][v.1 as usize].push(4);
            }
            // println!("4");
        }
        if (v.0 >=1 && v.0<= w+1) && (v.1 >=1 && v.1<= h+1)
        {
            if !vec[((v.0)-1) as usize][((v.1)-1) as usize].contains(&1)
            {
                vec[((v.0)-1) as usize][((v.1)-1) as usize].push(1);
            }
            // println!("1");
        }
        // else 
        // {
        //     vec[v.0 as usize][v.1 as usize].push(3);
        //     vec[((v.0)-1) as usize][v.1 as usize].push(4);
        //     vec[((v.0)-1) as usize][((v.1)-1) as usize].push(1);
        //     vec[v.0 as usize][((v.1)-1) as usize].push(2);
        // }
    }
    for _j in 0..(h-1)
    {
        for _i in 0..(w-1)
        {
            match vec[_i as usize][_j as usize].len() as i32
            {
                1=>{area += PI/4.0;
                    // println!("one");
                },
                2=>{
                    if abs(vec[_i as usize][_j as usize][0]-vec[_i as usize][_j as usize][1]) == 2
                    {
                        area += 1.0;
                        // println!("two");
                    }
                    else
                    {
                        area += PI/6.0 + SQRT_3/4.0;
                        // println!("_two")
                    }
                },
                3=>{
                    area +=1.0; 
                    // println!("three");
                },
                4=>{
                    area +=1.0; 
                    // println!("four");
                },
                _=>{
                    // println!("zero")
                },
            }
            // println!("area:{}",area);

        }
    }
    
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

// fn out_of_range(x:i32,y:i32,w:i32,h:i32) ->bool
// {
//     if x>w ||x<0 || y>h ||y<0
//     {
//         return true;
//     }
//     return false;
// }

// fn distance(v1:&(i32,i32), v2:&(i32,i32)) ->f64
// {
//     let x = abs(v1.0 - v2.0) as f64;
//     let y = abs(v1.1 - v2.1) as f64;
//     return (x*x + y*y).sqrt();
// }



fn abs(x:i32) ->i32
{
    if x<0
    {
        return -x;
    }
    x
}