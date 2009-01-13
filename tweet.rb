#stralcio
require 'net/http'
require 'uri'
module Tweet

  class Connection
  
    def initialize(usnm, passwd)
      
      @usnm = usnm
      @passwd = passwd

      
    end

    def login(data)

      url = URI.parse("http://twitter.com/statuses/update.json")
      req = Net::HTTP::Post.new(url.path)
      req.basic_auth(@usnm , @passwd)
      req.set_form_data({'status' => "RUBY ROCKS :O" }, ';')
      res = Net::HTTP.new(url.host, url.port).start {|http| http.request(req) }
      p res
      puts res.body


    end

  end


end
