Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

Example 1:

Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.



class Twitter {
public:

    // timer to maintain tweet order
    int timer;

    // user -> set of followees
    unordered_map<int, unordered_set<int>> follows;

    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({timer, tweetId});

        timer++;
    }

    vector<int> getNewsFeed(int userId) {

        vector<pair<int,int>> allTweets;

        // user should see own tweets also
        follows[userId].insert(userId);

        // collect tweets from everyone user follows
        for(auto followee : follows[userId]) {

            for(auto tweet : tweets[followee]) {

                allTweets.push_back(tweet);
            }
        }

        // sort by latest time descending
        sort(allTweets.begin(), allTweets.end(),
            [](pair<int,int>& a, pair<int,int>& b) {

                return a.first > b.first;
            });

        vector<int> feed;

        // take top 10 tweets
        for(int i = 0; i < min(10, (int)allTweets.size()); i++) {

            feed.push_back(allTweets[i].second);
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {

        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        // cannot unfollow yourself
        if(followerId != followeeId) {

            follows[followerId].erase(followeeId);
        }
    } 
};
