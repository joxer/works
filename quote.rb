require 'yaml'

module Quote
  
  
  class Write
    
    def initialize 
      
      @a = Array.new
      
    end 

       
    def add(quote)

      @a << quote.to_s

    end 
    
    def dump
      
      y = YAML::load(File.new("quote.yml"))
      r = Array.new
      if y != nil
        r = @a + y
      else
        r = @a
      end
      p r
      File.open("quote.yml", "w+") do |s|
       
        obj = YAML::dump( r)
        s.puts(obj)
        s.close
        
      end	

    end 
    
    

  end    

  class Read

    def read
      @f = YAML::load(File.new("quote.yml"))
      puts "VALUE #{@f}"
      
      return @f[rand( @f.length - 1) + 1 ]

    end

  end

end
