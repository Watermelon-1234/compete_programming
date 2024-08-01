struct Point {
    x: f64,
    y: f64,
}

fn distance_square(p1: &Point, p2: &Point) -> f64 {
    let dx = p1.x - p2.x;
    let dy = p1.y - p2.y;
    dx * dx + dy * dy
}

fn distance_square_form_line_to_origin(p1: &Point, p2: &Point) ->f64
{
    let m = (p1.x - p2.x)/(p1.y - p2.y);
    return (-1.0*m*p1.x)*(-1.0*m*p1.x)/(m*m+1.0);
}

fn main() {
    input!(n:i64);
    
    let mut points:Vec<Point> = Vec::new();

    for _ in 0..n
    {
        input!(  temp:[f64;2]);
        let p:Point = Point{
            x:temp[0],
            y:temp[1],
        };
        points.push(p);
    }


    let mut fathest_distance:f64 = 0.0;
    let mut closest_distance:f64 = f64::MAX;
    let origin = Point{
        x:0.0,
        y:0.0,
    };

    for i in 0..points.len() {
        let current_point = &points[i];
        let dist = distance_square(&origin, &current_point);//點到原點的距離
        if dist > fathest_distance {
            fathest_distance = dist;
        }
        if dist < closest_distance
        {
            closest_distance = dist;
        }

        // if fathest_distance < closest_distance {
        //     closest_distance = fathest_distance;
        // }
    }
    for i in 0..points.len() {
        let current_point = &points[i];

        for j in i..points.len() {
            let current_point_2 =&points[j];
            let dist = distance_square_form_line_to_origin(&current_point, &current_point_2);
            if dist < closest_distance
            {
                closest_distance = dist;
            }
            
        }

    }
    if fathest_distance < closest_distance {
        closest_distance = fathest_distance;
    }

    println!("closest:{},farthest:{}", closest_distance,fathest_distance);
}

#[macro_export]
macro_rules! input {
    () => {};
    (mut $var:ident: $t:tt, $($rest:tt)*) => {
        let mut $var = __input_inner!($t);
        input!($($rest)*)
    };
    ($var:ident: $t:tt, $($rest:tt)*) => {
        let $var = __input_inner!($t);
        input!($($rest)*)
    };
    (mut $var:ident: $t:tt) => {
        let mut $var = __input_inner!($t);
    };
    ($var:ident: $t:tt) => {
        let $var = __input_inner!($t);
    };
}
 
#[macro_export]
macro_rules! __input_inner {
    (($($t:tt),*)) => {
        ($(__input_inner!($t)),*)
    };
    ([$t:tt; $n:expr]) => {
        (0..$n).map(|_| __input_inner!($t)).collect::<Vec<_>>()
    };
    ([$t:tt]) => {{
        let n = __input_inner!(usize);
        (0..n).map(|_| __input_inner!($t)).collect::<Vec<_>>()
    }};
    (chars) => {
        __input_inner!(String).chars().collect::<Vec<_>>()
    };
    (bytes) => {
        __input_inner!(String).into_bytes()
    };
    (usize1) => {
        __input_inner!(usize) - 1
    };
    ($t:ty) => {
        $crate::read::<$t>()
    };
}
 
pub fn read<T>() -> T
where
    T: std::str::FromStr,
    T::Err: std::fmt::Debug,
{
    use std::cell::RefCell;
    use std::io::*;
 
    thread_local! {
        pub static STDIN: RefCell<StdinLock<'static>> = RefCell::new(stdin().lock());
    }
 
    STDIN.with(|r| {
        let mut r = r.borrow_mut();
        let mut s = vec![];
        loop {
            let buf = r.fill_buf().unwrap();
            if buf.is_empty() {
                break;
            }
            if let Some(i) = buf.iter().position(u8::is_ascii_whitespace) {
                s.extend_from_slice(&buf[..i]);
                r.consume(i + 1);
                if !s.is_empty() {
                    break;
                }
            } else {
                s.extend_from_slice(buf);
                let n = buf.len();
                r.consume(n);
            }
        }
        std::str::from_utf8(&s).unwrap().parse().unwrap()
    })
}
 
#[macro_export]
macro_rules! println {
    ($($arg:tt)*) => {
        $crate::write(|w| {
            use std::io::Write;
            std::writeln!(w, $($arg)*).unwrap()
        })
    };
}
 
#[macro_export]
macro_rules! print {
    ($($arg:tt)*) => {
        $crate::write(|w| {
            use std::io::Write;
            std::write!(w, $($arg)*).unwrap()
        })
    };
}
 
#[macro_export]
macro_rules! flush {
    () => {
        $crate::write(|w| {
            use std::io::Write;
            w.flush().unwrap()
        })
    };
}
 
pub fn write<F>(f: F)
where
    F: FnOnce(&mut std::io::BufWriter<std::io::StdoutLock>),
{
    use std::cell::RefCell;
    use std::io::*;
 
    thread_local! {
        pub static STDOUT: RefCell<BufWriter<StdoutLock<'static>>> =
            RefCell::new(BufWriter::new(stdout().lock()));
    }
 
    STDOUT.with(|w| f(&mut w.borrow_mut()))
}