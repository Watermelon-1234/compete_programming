use std::collections::VecDeque;
fn main(){
    input!{
        n:i64,
        values:[i64],
    }
    let mut nodes:Vec<Node> = Vec::new();
    for i in 0..n
    {
        nodes.push(Node{
            value : values[i as usize],
            to : Vec::new(),
        });
    }
    for _ in 0..((n-1) as usize)
    {
        input!{
            a:usize,
            b:i64
        }
        nodes[a].to.push(b);
    }

}

struct Node
{
    value:i64,
    to:Vec<i64>,

}

impl Node {
    fn bfs(&self, nodes: &Vec<Node>,current_value:i64,length:i64) ->i64//return max_length
    {
        let mut queue = VecDeque::new();
        let mut visited = vec![false; nodes.len()];
        queue.push_back(0); // 假設 BFS 從節點 0 開始
        visited[0] = true;
        let mut max_length = 0;
        while let Some(current) = queue.pop_front() {
            // println!("Visited node with value: {}", nodes[current].value);
            let length  = node[current].self.dfs(nodes, &mut visited, current,self.value,0);
            if length>max_length
            {
                length=max_length;
            }
            for &neighbor in &nodes[current].to {
                if !visited[neighbor] {
                    queue.push_back(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    fn dfs(&self, nodes: &Vec<Node>, visited: &mut Vec<bool>, current: usize,current_value:i64,length:i64) ->i64
    {
        if visited[current] {
            return length;
        }
        visited[current] = true;
        // println!("Visited node with value: {}", nodes[current].value);
        if current_value< self.value
        {
            length+=1;
        }
        for &neighbor in &nodes[current].to {
            if !visited[neighbor] {
                length = nodes[current].self.dfs(nodes, visited, neighbor,self.value,length);
            }
        }
    }
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

