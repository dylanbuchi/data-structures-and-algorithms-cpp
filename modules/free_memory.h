template <typename Node>
void FreeMemoryFromLinkedList(Node *&head) {
    if (head) {
        while (head) {
            auto *to_delete = head;
            head = head->next;

            delete to_delete;
            to_delete = nullptr;
        }

        head = nullptr;
    }
}