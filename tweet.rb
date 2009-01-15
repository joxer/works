#stralcio
require 'net/http'
require 'uri'
module Tweet

  class Status
  
    def initialize(usnm, passwd)
      
      @usnm = usnm
      @passwd = passwd

    end

    def send_msg(data)

      url = URI.parse("http://twitter.com/statuses/update.xml")
      req = Net::HTTP::Post.new(url.path)
      req.basic_auth(@usnm , @passwd)
      req.set_form_data({'status' => "#{data}" }, ';')
      res = Net::HTTP.new(url.host, url.port).start {|http| http.request(req) }
      return res
      


    end

    def public_timeline(format = "xml")
      
      url = URI.parse("http://twitter.com/statuses/public_timeline.#{format}")
      req = Net::HTTP::Get.new(url.path)
      req.basic_auth(@usnm, @passwd)
      res = Net::HTTP.new(url.host, url.port).start { |http| http.request(req) }
      return res
     

    end

    def friends_timeline(format = "xml")

      url = URI.parse("http://twitter.com/statuses/friends_timeline.#{format}")
      req = Net::HTTP::Get.new(url.path)
      req.basic_auth(@usnm, @passwd)
      res = Net::HTTP.new(url.host, utl.port).start{ |http| http.request(req) }
      return res
      

    end

    def user_timeline(user, format = "xml")

      url = URI.parse("http://twitter.com/statuses/user_timeline/#{user}.#{format}")
      req = Net::HTTP::Get.new(url.path)
      req.basic_auth(@usnm, @passwd)
      res = Net::HTTP.new(url.host, utl.port).start{ |http| http.request(req) }
      return res
      

      
    end

    
    def show(id, format = "xml")

      url = URI.parse("http://twitter.com/statuses/user_timeline/#{id}.#{format}")
      req = Net::HTTP::Get.new(url.path)
      req.basic_auth(@usnm, @passwd)
      res = Net::HTTP.new(url.host, utl.port).start{ |http| http.request(req) }
      return res
      

      
    end

    def destroy(id, format = "xml")

    
      url = URI.parse("  http://twitter.com/statuses/destroy/#{id}.#{format}")
      req = Net::HTTP::Get.new(url.path)
      req.basic_auth(@usnm, @passwd)
      res = Net::HTTP.new(url.host, utl.port).start{ |http| http.request(req) }
      return res
      

    end
    
 end


end
