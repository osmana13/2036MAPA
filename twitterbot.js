var Twitter = require('twitter');
 
var client = new Twitter({
  consumer_key: 'ub65wYU9BRnsP5zlvIoeLhmtz',
  consumer_secret: 'UjObw8PG3nEqy8qlX7pnqSganerps0juYHlk5bg31bcRiCKL6G',
  access_token_key: '948968097460957184-PCmcVVsCvG2fFk3HZYpCJ1bEv4HvBuM',
  access_token_secret: 'VjDGmR6k4MBcmQzmYHstk9kFDegt1clrQhnthBOoiKLmG'
});


client.post('statuses/update', {status: 'ayan the coder3'},  // tweets for you
  function(error, tweet, response) {
  if(error) throw error;
  console.log(tweet);  // Tweet body. 
  console.log(response);  // Raw response object. 
});

client.get('search/tweets', {q: 'blackpanter'}, //search hashtag
   function(error, tweets, response) {
   console.log(tweets);
});

var params = {screen_name: 'ayancoder'}; //
client.get('statuses/user_timeline', params, function(error, tweets, response) {
  if (!error) {
    console.log(tweets);
  }
});

