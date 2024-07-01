#ifndef VIDEOLISTTYPE_H
#define VIDEOLISTTYPE_H

#include "../linkedList.h"
#include "../unorderLinkedList.h"
#include "videoType.h"
#include <string>

class VideoListType : public UnorderedLinkedList<VideoType> {
public:
  bool videoSearch(std::string title) const {
    bool found = false;
    NodeType<VideoType> *location;

    searchVideoList(title, found, location);

    return found;
  }

  bool isVideoAvailable(std::string title) const {
    bool found;
    NodeType<VideoType> *location;

    searchVideoList(title, found, location);
    if (found)
      found = location->info.getNoOfCopiesInStock() > 0;
    else
      found = false;
    return found;
  }

  void checkOut(std::string title) {
    bool found;
    NodeType<VideoType> *location;
    searchVideoList(title, found, location);

    if (found)
      location->info.checkOut();
    else
      std::cout << "Not found, Title: " << title << std::endl;
  }

  void checkIn(std::string title) {
    bool found;
    NodeType<VideoType> *location;
    searchVideoList(title, found, location);

    if (found)
      location->info.checkIn();
    else
      std::cout << "Not found, Title: " << title << std::endl;
  }

  bool videoCheckTitle(std::string title) const {
    bool found = false;
    NodeType<VideoType> *location;

    searchVideoList(title, found, location);
    return found;
  }

  void videoUpdateInStock(std::string title, int num) {
    bool found = false;
    NodeType<VideoType> *location;

    searchVideoList(title, found, location);

    if (found)
      location->info.updateInStock(num);
    else
      std::cout << "Not found, Title: " << title << std::endl;
  }

  void videoSetCopiesInStock(std::string title, int num) {
    bool found = false;
    NodeType<VideoType> *location;

    searchVideoList(title, found, location);

    if (found)
      location->info.setInStock(num);
    else
      std::cout << "Not found, Title: " << title << std::endl;
  }

  void videoPrintTitle() const {
    NodeType<VideoType> *current;

    current = first;
    while (current != nullptr) {
      current->info.printTitle();
      current = current->link;
    }
  }

private:
  void searchVideoList(std::string title, bool &found,
                       NodeType<VideoType> *&current) const {
    found = false;
    current = first;

    while (current != nullptr && !found) {
      if (current->info.checkTitle(title))
        found = true;
      else
        current = current->link;
    }
  }
};

#endif // VIDEOLISTTYPE_H
