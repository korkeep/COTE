from collections import defaultdict

def solution(genres, plays):
    answer = list()
    
    # make dictionary of int value
    play_count_by_genre = defaultdict(int)
    # make dictionary of list value
    songs_in_genre = defaultdict(list)
    
    # to make dictionary, use zip!
    for song_id, genre, play in zip(counter(), genres, plays):
        # check the num of each genre play
        play_count_by_genre[genre] += play
        
        # use '-'play to sort by once
        songs_in_genre[genre].append((-play, song_id))
                
    # sort genre list with num of play by descending order 
    genre_in_order = sorted(play_count_by_genre.keys(), 
                            key=lambda g:play_count_by_genre[g], reverse=True)
    
    for genre in genre_in_order:
        # extend songs in genre with the most popular order
        answer.extend([ song_id for minus_play, 
                       song_id in sorted(songs_in_genre[genre])[:2]])
    return answer

def counter():
    i = 0
    while True:
        yield i
        i += 1
