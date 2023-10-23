select tweet_id  
from Tweets
where char_length(content) > 15;

-- # SELECT LENGTH('€')  # is equal to 3 length give value in byte 
-- # SELECT CHAR_LENGTH('€') # is equal to 1