let now_playing = document.querySelector('.now-playing');
let track_art = document.querySelector('.track-art');
let track_name = document.querySelector('.track-name');
let track_artist = document.querySelector('.track-artist');

let playpause_btn = document.querySelector('.playpause-track');
let next_btn = document.querySelector('.next-track');
let prev_btn = document.querySelector('.prev-track');

let seek_slider = document.querySelector('.seek_slider');
let curr_time = document.querySelector('.current-time');
let total_duration = document.querySelector('.total-duration');
let randomIcon = document.querySelector('.fa-random');
let curr_track = document.createElement('audio');

let track_index = 0;
let isPlaying = false;
let isRandom = false;
let updateTimer;


const music_list = [
    {
        img : './images/kkcd.png',
        name : 'Kya Mujhe Pyar Hai',
        artist : 'Woh Lamhe',
        music : 'music/Kya Mujhe Pyar Hai.mp3',
        length : '04:12'
    },
    {
        img : './images/kkcd.png',
        name : 'Zara Sa',
        artist : 'Jannat: In Search of Heaven',
        music : 'music/Zara Sa.mp3',
        length : '05:04'
    },
    {
        img : './images/kkcd.png',
        name : 'Ajab Si',
        artist : 'Om Shanti Om',
        music : 'music/Ajab Si.mp3',
        length : '04:06'
    },
    {
        img : './images/kkcd.png',
        name : 'Dil Ibaadat',
        artist : 'Jannat: In Search of Heaven',
        music : 'music/Dil Ibaadat.mp3',
        length : '05:29'
    },
    {
        img : './images/kkcd.png',
        name : 'Tu Hi Meri Shab Hai',
        artist : 'Gangster: A Love Story',
        music : 'music/Tu Hi Meri Shab Hai.mp3',
        length : '06:30'
    },
    {
        img : './images/kkcd.png',
        name : 'Sajde',
        artist : 'Khatta Meetha',
        music : 'music/Sajde.mp3',
        length : '05:08'
    },
    {
        img : './images/kkcd.png',
        name : 'Labon Ko',
        artist : 'Bhool Bhulaiyaa',
        music : 'music/Labon Ko.mp3',
        length : '05:44'
    },

    {
        img : './images/kkcd.png',
        name : 'Khuda Jaane',
        artist : 'Bachna Ae Haseeno',
        music : 'music/Khuda Jaane.mp3',
        length : '05:33'
    },
    {
        img : './images/kkcd.png',
        name : 'Piya Aaye Na',
        artist : 'Aashiqui 2',
        music : 'music/Piya Aaye Na.mp3',
        length : '04:46'
    },
    {
        img : './images/kkcd.png',
        name : 'Sach Keh Raha Hai',
        artist : 'Rehnaa Hai Terre Dil Mein',
        music : 'music/Sach Keh Raha Hai.mp3',
        length : '05:27'
    }
];

loadTrack(track_index);

function loadTrack(track_index){
    clearInterval(updateTimer);
    reset();

    curr_track.src = music_list[track_index].music;
    curr_track.load();

    track_art.style.backgroundImage = "url(" + music_list[track_index].img + ")";
    track_name.textContent = music_list[track_index].name;
    track_artist.textContent = music_list[track_index].artist;
    now_playing.textContent = "KK ❤️❤️  " + (track_index + 1) + " / " + music_list.length;

    updateTimer = setInterval(setUpdate, 1000);

    curr_track.addEventListener('ended', nextTrack);
}

function reset(){
    curr_time.textContent = "00:00";
    total_duration.textContent = music_list[track_index].length;
    seek_slider.value = 0;
}
function randomTrack(){
    isRandom ? pauseRandom() : playRandom();
}
function playRandom(){
    isRandom = true;
}
function pauseRandom(){
    isRandom = false;
}
function repeatTrack(){
    let current_index = track_index;
    loadTrack(current_index);
    playTrack();
}
function playpauseTrack(){
    isPlaying ? pauseTrack() : playTrack();
}
function playTrack(){
    curr_track.play();
    isPlaying = true;
    track_art.classList.add('rotate');
    playpause_btn.innerHTML = '<i class="fa fa-pause-circle fa-5x"></i>';
}
function pauseTrack(){
    curr_track.pause();
    isPlaying = false;
    track_art.classList.remove('rotate');
    playpause_btn.innerHTML = '<i class="fa fa-play-circle fa-5x"></i>';
}
function nextTrack(){
    if(track_index < music_list.length - 1 && isRandom === false){
        track_index += 1;
    }else if(track_index < music_list.length - 1 && isRandom === true){
        let random_index = Number.parseInt(Math.random() * music_list.length);
        track_index = random_index;
    }else{
        track_index = 0;
    }
    loadTrack(track_index);
    playTrack();
}
function prevTrack(){
    if(track_index > 0){
        track_index -= 1;
    }else{
        track_index = music_list.length -1;
    }
    loadTrack(track_index);
    playTrack();
}
function seekTo(){
    let seekto = curr_track.duration * (seek_slider.value / 100);
    curr_track.currentTime = seekto;
}
function setUpdate(){
    let seekPosition = 0;
    if(!isNaN(curr_track.duration)){
        seekPosition = curr_track.currentTime * (100 / curr_track.duration);
        seek_slider.value = seekPosition;

        let currentMinutes = Math.floor(curr_track.currentTime / 60);
        let currentSeconds = Math.floor(curr_track.currentTime - currentMinutes * 60);
        let durationMinutes = Math.floor(curr_track.duration / 60);
        let durationSeconds = Math.floor(curr_track.duration - durationMinutes * 60);

        if(currentSeconds < 10) {currentSeconds = "0" + currentSeconds; }
        if(durationSeconds < 10) { durationSeconds = "0" + durationSeconds; }
        if(currentMinutes < 10) {currentMinutes = "0" + currentMinutes; }
        if(durationMinutes < 10) { durationMinutes = "0" + durationMinutes; }

        curr_time.textContent = currentMinutes + ":" + currentSeconds;
        // total_duration.textContent = durationMinutes + ":" + durationMinutes;
    }
}
