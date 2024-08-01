use std::cmp::min;
fn main() {
    println!("Thank you kiwi, you are truly a superman!");
    let (n,m,k):(i32,i32,i32) = trible_cin();
    let mut current:Vec<i32> = vec![-1,-1];
    let mut pass:bool = true;
    // let mut first = -1;
    // let mut second = -1;
    for _i in 0..m
    {
        if fuck_up(n,k,&mut current) == false
        {
            pass = false;
        }
    }
    if pass
    {
        println!("My god, the grand kiwi superman, you are so dian Orz");
    }
    else
    {
        println!("My god, the grand kiwi superman, I'm so sorry, I'll remove the chart from the game as soon as possible, I promise.");
    }
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

fn fuck_up(n:i32,k:i32,current:&mut Vec<i32>)->bool
{
    let mut input_str = String::new();
    std::io::stdin().read_line(&mut input_str).expect("");
    // let input_str = input_str.trim().parse().expect("");
    let bytes = input_str.as_bytes();
    let mut _new:Vec<i32> = Vec::new();
    for (index, c) in bytes.iter().enumerate() 
    {
        if *c == b'_'
        {
            _new.push(index as i32);
        }
    }
    if _new.is_empty()// relax row
    {
        current.clear();
        current.push(-1);
        current.push(-1);
        return true;
    }
    else if current[0] == -1 && current[1] == -1//last row is relaxed
    {
        current.clear();
        current.push(_new.pop().unwrap());
        current.push(_new.pop().unwrap());
        return true;
    }
    else if (min(abs(_new[1]-current[1]),n-abs(_new[1]-current[1]))<=k 
        && min(abs(_new[0]-current[0]),n-abs(_new[0]-current[0]))<=k)
        ||(min(abs(_new[1]-current[0]),n-abs(_new[1]-current[0]))<=k 
        && min(abs(_new[0]-current[1]),n-abs(_new[0]-current[1]))<=k)//交替or not
    {
        return true;
    }
    false
}

fn abs(x:i32)->i32
{
    if x>=0
    {
        return x;
    }
    return -x;
}