
t, b = 0, 0
N = 2
N2 = 2
q = Hash.new

N.upto(N*N2) do |s|

  q[s] = 0

end

p q



def a (n ,s , q)
      
  if n == 0
    p s
    q[s] += 1
  else
    
    1.upto(N2) do |r|
      
      a(n-1, s+r, q)

    end
  end
end

a(N, 0, q)

p q.sort
