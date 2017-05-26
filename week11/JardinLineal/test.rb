def test(conf)
  ones = conf.reduce(&:+)
  zeros = conf.length - ones
  if (ones - zeros).abs <= 2
    return true
  else
    puts "ones: #{ones} zeros: #{zeros} conf: #{conf}"
  end
end

def is_valid?(conf)
  conf.each_with_index do |_, i|
    0.upto(i) do |j|
      return false unless test(conf[j..i])
    end
  end
  true
end

File.readlines('out.txt').each do |line|
  line = line.chomp.split(//).map { |d| d.to_i }
  unless is_valid?(line)
    puts "Invalid: #{line}"
  end
end
