#include<bits/stdc++.h>
#include<vector>

int c,w,h;
vector<vector<vector>> vec ;


int main()
{
    for (int i = 0; i <210;i++)
    {
        vector<vector> temp;
        for (int j = 0; j <210;j++)
        {
            vector<int> _temp;
            temp.push_back(_temp);
        } 
        vec.push_back(temp);
    }
    cin>>c>>w>>h;
    for (int i=0;i<w;i++)
    {
        int a,b;
        cin>>a>>b;
        if (a >=0 && a <=w) && (b >= 0 && b <=h)
        {
            vec[a][b].push(3);
        }
        if (a >= 0 && a<= w) && (b >=1 && b<= h+1)
        {
            vec[a][((b)-1)].push(2);
        }
        if (a>=1 && a <= w+1) && (b >= 0 && b<= h)
        {
            vec[((a)-1)][b].push(4);
        }
        if (a >=1 && a<= w+1) && (b >=1 && b<= h+1)
        {
            vec[((a)-1)][((b)-1)].push(1);
        }
    }
    for (int i = 0;i<h;i++)
    {
        for(int j = 0;j<)
        {
            match vec[_i as usize][_j as usize].len() as i32
            {
                1=>{area += PI/4.0},
                2=>{
                    if abs(vec[_i as usize][_j as usize][0]-vec[_i as usize][_j as usize][1]) == 2
                    {
                        area += 1.0;
                    }
                    else
                    {
                        area += PI/6.0 + SQRT_3/4.0;
                    }
                },
                3=>{area +=1.0},
                4=>{area +=1.0},
                _=>()
            }

        }
    }
    
    println!("{:.}",area/max_area)
}