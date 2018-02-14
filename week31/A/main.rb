#!/usr/bin/env ruby
encoded = [
  "ejp mysljylc kd kxveddknmc re jsicpdrysi",
  "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
  "de kr kd eoya kw aej tysr re ujdr lkgc jv"
]

decoded = [
  "our language is impossible to understand",
  "there are twenty six factorial possibilities",
  "so it is okay if you want to just give up"
]

map = {}
0.upto(2) do |i|
  0.upto(encoded[i].length - 1) do |j|
    key = encoded[i][j]
    value = decoded[i][j]
    map[key] = value
  end
end

map['z'] = 'q'
map['q'] = 'z'
list = map.map {|e| e}.sort
# newlist = []
list.each do |item|
  # newlist.push(item[0])
  # puts "#{item}"
end
# puts "#{newlist.sort}"
n = STDIN.gets.chomp.to_i
1.upto(n) do |tc|
  print "Case ##{tc}: "
  text = STDIN.gets.chomp
  text.chars do |ch|
    print map[ch]
  end
  puts
end
