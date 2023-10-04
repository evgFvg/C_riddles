iterator_t FindNthElementsFromTail(sll_t *sll, size_t n)
{
    iterator_t fast = NULL;
    iterator_t slow = NULL;
    iterator_t tail = NULL;

    assert(sll != NULL);

    slow = SLLBeginIter(sll);
    fast = GetNthIteratorFromHead(slow, n);
    tail = SLLEndIter(sll);

    while (tail != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

iterator_t GetNthIteratorFromHead(iterator_t head, size_t n)
{
    while (0 < n && NULL != head->next)
    {
        head = head->next;
        --n;
    }
    return head;
}
