#!/usr/bin/ruby

require 'socket'
require 'quote'
class Phrase

  def rp
    
    p = { 0 => "A me bastano 2 prosciutti!" , 1 => "dican quel che dican, Bleed puzza", 2 => "Il sole domani non sorge, suka!",3 => "ponzi ponzi popopo", 4 => "Da grande voglio diventare l'anti-Bleed", 5 => "42!!!!!!!!", 6=> "Bleed sei un vogon!", 7 => "VI ODIO", 8 => "CALCIO ROTANTE!!!!!", 9 => "GANJA GANJA GANJA!"}


    b = rand * 10
    return p[b.round]
  end

  

end

class Dado

  def initialize

    @a = Hash.new

  end
  
   end
public
  def somma(name, value)

    if @a.key?(name) == true

      @a[name] += value

    else

      @a[name] = value

    end
    
    return @a[name]

  end

  
  def dado(name)

    b = rand * 100
    return somma(name , b.round), b.round

 

end



class Bot

  def initialize
    @w = Quote::Write.new
    @re = Quote::Read.new
    @r = Phrase.new
    @d = Dado.new
    @server = "crypto.azzurra.org"
    @nick = "boxer`"
    @passwd = "QAZWSXEDC"
    @chan = "#ruby-lang"
    @so = TCPSocket.new(@server, 6667)
  end
  
  def send(s)
    @so.send "#{s}\n", 0
  end

  def bash(recv)
    puts "COMMAND #{recv}"
    b = `#{recv}`.chop
    
    send("PRIVMSG #{@chan} :#{b.gsub("\n", "")}")

  end

  def con

    send("USER boxer` boxer` boxer`:boxer` boxer`")
    send("NICK #{@nick}")
    send("NS IDENTIFY #{@passwd}")
    send("JOIN #{@chan}")
    
  end

  def rec
   
    Thread.new do
    
      trap(2) do |s|
      
        @w.dump
        puts "TERMINATED"
        exit(0)
	end


    end    


    while true
      ric = @so.gets
      puts ric
     
      
      if ric =~ /PING/
        send("PONG")
      end      
      
      if ric =~ /^:joxer.*.!play/
        puts "scrivo artista"
        title = `dcop amarok player title`.chop
        artisti = `dcop amarok player artist`.chop
        send("PRIVMSG #{@chan} :joxer is listening #{title} by #{artisti}")
        
      end
      
      if ric =~ /ciao boxer/
        send("PRIVMSG #{@chan} :ciao anche a te =))))")
      end
      
      if ric =~ /(:=O|::O)/
	send("PRIVMSG #{@chan} :=O!")
      end
	
       if ric =~ /auguri/
	send("PRIVMSG #{@chan} :ANGURIE!!!")
       end

      if ric =~ /EVVAI/
        send("PRIVMSG #{@chan} :EVVAI!!!")
	end
      
      if ric =~ /~phrase/
        
        send("PRIVMSG #{@chan} :#{@r.rp}")
        
      end

      if ric =~ /vero/
          send("PRIVMSG #{@chan} :concordo u.u")
      end
      
      if ric =~ /~amore/
        a = ric.split
        send("PRIVMSG #{@chan} :ti amo #{a[4]} :*********** ")
      end

      if ric =~ /~parroco/
        a = ric.split
	send("PRIVMSG #{@chan} :#{a[4]} e #{a[5]} siete marito e moglie :)))")
      end

      if ric =~ /^:joxer\!\~.*.!logoff/
        send("QUIT :ADDIO MONDO, BLEED PUZZA RICORDATE")
        @w.dump
        puts "TERMINATED"
        exit(0)
      
      end
      
=begin      
      if ric =~ /^:joxer\!\~.*.!ruby/
        a = ric.split
        c =  `ruby -e '#{a[4..-1]}'`.chop
        send("PRIVMSG #{@chan} :#{c}")
      end
=end

      if ric =~ /!dado/

        e = ric.sub(":", "").split(/!/)
        a, b = @d.dado(e[0])
        p a, b
        send("PRIVMSG #{@chan} :#{e[0]} hai fatto #{b} punti, ne hai #{a} totali")
      end

      if ric=~ /(gay|merda|porco|affanculo|stronzo)/
        send("PRIVMSG #{@chan} :AEH")
      end

      if ric =~ /PRIVMSG.*.(Bleed|bleed).*/
        send("PRIVMSG #{@chan} :ti odio bleed")
      end
      
      if ric =~ /(!HELP|!help)/
	send( "PRIVMSG #{@chan} :help e' per nabbi u.u" )
      end
      
      if ric =~ /!man/
	send("PRIVMSG #{@chan} :comandi: EVVAI, vero, bleed, auguri, ~phrase, ~parroco, ~amore, !dado, !quote, !read, !dump")
      end

=begin
      if ric =~ /^:joxer\!\~.*.!bash/
        
        b = ric.split("#{@chan}")
        b[1].sub!(":", "")
        c = b[1].split("!bash=")
        bash(c)
      end
=end

      if ric =~ /!quote/
        
        r = ric.split /!quote=/
        if r != nil
        @w.add(r[1].chop)
        end
          

      end

      if ric =~ /!dump/

        @w.dump

      end

      if ric =~ /!read/
        p @re.read
        send("PRIVMSG #{@chan} :#{@re.read}")

      end

      if ric =~ /JOIN/

        a = ric.chop.split(/!.*/)
        b = a[0].split(":")
        p b
        b.class
        puts b
        if b[1] =~ /boxer`/
        else
          send("PRIVMSG #{@chan} :ciao #{b}, benvenuto nel chan, prima di andartene ricordati di pagare il pizzo")
        end
      end
    end
  end
  end
b = Bot.new
b.con
b.rec
