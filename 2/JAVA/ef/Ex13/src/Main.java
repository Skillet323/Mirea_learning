interface MediaPlayer {
    void play(String audioType, String fileName);
}

class MP3Player implements MediaPlayer {
    @Override
    public void play(String audioType, String fileName) {
        if (audioType.equalsIgnoreCase("mp3")) {
            System.out.println("Воспроизводим MP3 файл: " + fileName);
        } else {
            System.out.println("Неподдерживаемый формат: " + audioType);
        }
    }
}

class WAVPlayer {
    public void playWAV(String fileName) {
        System.out.println("Воспроизводим WAV файл: " + fileName);
    }
}

class WAVAdapter implements MediaPlayer {
    private WAVPlayer wavPlayer;

    public WAVAdapter() {
        this.wavPlayer = new WAVPlayer();
    }

    @Override
    public void play(String audioType, String fileName) {
        if (audioType.equalsIgnoreCase("wav")) {
            wavPlayer.playWAV(fileName);
        } else {
            System.out.println("Неподдерживаемый формат: " + audioType);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        MediaPlayer mp3Player = new MP3Player();
        MediaPlayer wavAdapter = new WAVAdapter();

        mp3Player.play("mp3", "song.mp3");
        wavAdapter.play("wav", "track.wav");
        mp3Player.play("wav", "track.wav");
    }
}
