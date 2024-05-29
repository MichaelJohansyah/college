/*
Michael Johanes Johansyah
L0123081
Informatika C
Program simulasi Music Player
*/

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>

// Struktur untuk lagu
struct Song {
  std::string title;
  std::string artist;
};

// Fungsi untuk display lagu
void displaySong(const Song& song) {
  std::cout << "Title: " << song.title << std::endl;
  std::cout << "Artist: " << song.artist << std::endl;
}

// Fungsi untuk menambah lagu ke playlist
void addSong(std::list<Song>& playlist) {
  Song newSong;
  std::cout << "Enter song title: ";
  std::cin.ignore();
  std::getline(std::cin, newSong.title);
  std::cout << "Enter song artist: ";
  std::getline(std::cin, newSong.artist);
  playlist.push_back(newSong);
  std::cout << "Song added to playlist!\n";
}

// Fungsi untuk menghapus lagu
bool removeSong(std::list<Song>& playlist, std::stack<Song>& undoStack) {
  if (playlist.empty()) {
    std::cout << "Playlist is empty! Please add your song first!\n";
    return false;
  }

  int index;
  std::cout << "\nEnter song index to remove (starting from 0): ";
  std::cin >> index;

  if (index >= 0 && index < playlist.size()) {
    auto it = playlist.begin();
    std::advance(it, index);
    Song removedSong = *it;
    playlist.erase(it);
    undoStack.push(removedSong);
    std::cout << "Song removed from playlist!\n";
    return true;
  } else {
    std::cout << "Invalid index!\n";
    return false;
  }
}

// Fungsi untuk memutar lagu 
void playSongs(std::list<Song>& playlist, std::queue<Song>& playbackQueue) {
  // Mengecek jika playback queue kosong dan playlist tidak kosong
  if (playbackQueue.empty() && !playlist.empty()) {
    // Memindahkan semua lagu dari playlist ke playback queue
    while (!playlist.empty()) {
      playbackQueue.push(playlist.front());
      playlist.pop_front();
    }
    std::cout << "Now playing: \n";
    displaySong(playbackQueue.front());
    // Simulasi mendengarkan lagu
    std::cout << "** Simulating playback... **\n";
  } else if (playbackQueue.empty()) {
    std::cout << "Playlist is empty! Please add your song first!\n";
  }
}

// Fungsi untuk memutar lagu selanjutnya dari playback queue
void playNextSong(std::queue<Song>& playbackQueue) {
  if (playbackQueue.empty()) {
    std::cout << "Playback queue is empty! Please add your song first!\n";
    return;
  }

  // Mengeluarkan lagu sekarang dari playback queue
  playbackQueue.pop();

  // Mengecek apakah masih ada lagu selanjutnya
  if (playbackQueue.empty()) {
    std::cout << "Reached the end of playback queue.\n";
  } else {
    std::cout << "\nNow playing: \n";
    displaySong(playbackQueue.front());
    // Simulasi pemutaran lagu
    std::cout << "** Simulating playback... **\n";
  }
}

// Fungsi untuk display playlist
void displayPlaylist(const std::list<Song>& playlist) {
  if (playlist.empty()) {
    std::cout << "Playlist is empty! Please add your song first!\n";
    return;
  }
  int index = 0;
  std::cout << "\nPlaylist:\n";
  for (const Song& song : playlist) {
    std::cout << index << ". ";
    displaySong(song);
    index++;
  }
}

// Fungsi untuk Undo lagu yang sudah dihapus
void undoRemoval(std::stack<Song>& undoStack, std::list<Song>& playlist) {
  if (undoStack.empty()) {
    std::cout << "No recent songs removed. Nothing to undo.\n";
    return;
  }

  Song undoSong = undoStack.top();
  undoStack.pop();
  playlist.push_back(undoSong);
  std::cout << "Undo: Removed song \"" << undoSong.title << "\" has been added back to playlist.\n";
}

int main() {
  // Membuat list lagu dengan nama playlist
  std::list<Song> playlist;

  // Membuat queue untuk playback queue
  std::queue<Song> playbackQueue;

  // Membuat stack untuk lagu yang dihapus nantinya
  std::stack<Song> undoStack;
  

  // Bagian menentukan pilihan
  while (true) {
    int choice;
    std::cout << "\nMusic Player Playlist\n";
    std::cout << "1. Add Song\n";
    std::cout << "2. Remove Song\n";
    std::cout << "3. Play\n";
    std::cout << "4. Next Song\n";
    std::cout << "5. Display Playlist\n";  
    std::cout << "6. Undo Removed Song\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << "\n";

    switch (choice) {
      case 1: {
        addSong(playlist);
        break;
      }
      case 2: {
        displayPlaylist(playlist);
        if (removeSong(playlist, undoStack)) {}
        break;
      }
      case 3: {
        playSongs(playlist, playbackQueue);
        break;
      }
      case 4: {
        playNextSong(playbackQueue);
        break;
      }
      case 5: {
        displayPlaylist(playlist);
        break;
      }
      case 6: {
        undoRemoval(undoStack, playlist);
        break;
      }
      case 7: {
        // Keluar dari program
        std::cout << "Exiting Music Player Playlist.\n";
        return 0;
      }
      default:
        std::cout << "Invalid choice!\n";
    }
  }

  return 0;
}