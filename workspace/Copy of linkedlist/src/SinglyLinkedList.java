/*  Class Node  */
class Node {
	int data;
	Node link;

	/* Constructor */
	public Node() {
		link = null;
		data = 0;
	}

	/* Constructor */
	public Node(int d, Node n) {
		data = d;
		link = n;
	}

	/* Function to set link to next Node */
	public void setLink(Node n) {
		link = n;
	}

	/* Function to set data to current Node */
	public void setData(int d) {
		data = d;
	}

	/* Function to get link to next node */
	public Node getLink() {
		return link;
	}

	/* Function to get data from current Node */
	public int getData() {
		return data;
	}
}

/* Class linkedList */
class linkedList {
	Node start;
	Node end;
	public int size;

	/* Constructor */
	public linkedList() {
		start = null;
		end = null;
		size = 0;
	}

	/* Function to get size of list */
	public int getSize() {
		return size;
	}

	/* Function to insert an element at end */
	public void firstNode(int val) {
		Node nptr = new Node(val, null);
		start = nptr;
		end = start;
	}

	public void secondNode(int val) {
		Node nptr = new Node(val, null);
		end.setLink(nptr);
		end = nptr;
	}

	public void deleteAtEnd(int pos) {
		if (pos == size) {
			Node s = start;
			Node t = start;
			while (s != end) {
				t = s;
				s = s.getLink();
			}
			end = t;
			end.setLink(null);
			size--;
			return;
		}
	}

	/* Function to display elements */
	public void display() {
		System.out.print("Singly Linked List = ");

		if (start.getLink() == null) {
			System.out.println(start.getData());
			return;
		}
		Node ptr = start;
		System.out.print(start.getData() + "->");
		ptr = start.getLink();
		while (ptr.getLink() != null) {
			System.out.print(ptr.getData() + "->");
			ptr = ptr.getLink();
		}
		System.out.print(ptr.getData() + "\n");
	}
}

/* Class SinglyLinkedList */
public class SinglyLinkedList {
	public static void main(String[] args) {
		/* Creating object of class linkedList */
		linkedList list = new linkedList();
		/* Perform list operations */
		int n1 = 6;
		int n2 = 5;
		list.firstNode(n1);
		list.secondNode(n2);
		System.out.println("Singly Linked List = " + list.start.getData());
		list.display();
		int p = list.getSize();
		list.deleteAtEnd(p);
		list.display();
	}

}
