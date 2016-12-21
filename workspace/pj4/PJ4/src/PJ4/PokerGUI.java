package PJ4;

import java.awt.FileDialog;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.SpringLayout;

class winlisc implements WindowListener {
	public void windowActivated(WindowEvent e) {
		System.out.println("Activated event");
		PokerGUI.skeletonwindowframe.requestFocusInWindow();
		PokerGUI.skeletonmainwindow.repaint();
	}

	public void windowClosed(WindowEvent e) {
		System.out.println("Close event");
	}

	public void windowClosing(WindowEvent e) {
		System.out.println("Closing event");
		try {
			System.exit(0);
		} catch (SecurityException err) {
			System.out.println("can not exit");
		}
	}

	public void windowDeactivated(WindowEvent e) {
		System.out.println("Deactivated event");
	}

	public void windowDeiconified(WindowEvent e) {
		System.out.println("Deiconified event");
	}

	public void windowIconified(WindowEvent e) {
		System.out.println("Iconified event");
	}

	public void windowOpened(WindowEvent e) {
		System.out.println("Opened event");
	}

}

class actlisc implements ActionListener {
	public void actionPerformed(ActionEvent e) {
		String action = e.getActionCommand();
		System.out.println("action " + action);
		if (action.equals("menunew")) {
			System.out.println("new");
		}
		if (action.equals("menuopen")) {
			System.out.println("open");
			FileDialog fd = new FileDialog(PokerGUI.skeletonwindowframe,
					"open game", FileDialog.LOAD);
			fd.show();
			String filename = fd.getDirectory() + fd.getFile();
			if (fd.getFile() != null) {
				try {
					// code that opens a file goes here
				} catch (Exception err) {
					System.out.println(err.getMessage());
				}
			}
			PokerGUI.skeletonwindowframe.requestFocusInWindow();
			PokerGUI.skeletonmainwindow.repaint();
		}
		if (action.equals("menusave")) {
			System.out.println("save");
			FileDialog fd = new FileDialog(PokerGUI.skeletonwindowframe,
					"save game", FileDialog.SAVE);
			fd.show();
			String filename = fd.getDirectory() + fd.getFile();
			if (fd.getFile() != null) {
				try {
					// code that saves a file goes here
				} catch (Exception err) {
					System.out.println(err.getMessage());
				}
			}
			PokerGUI.skeletonwindowframe.requestFocusInWindow();
			PokerGUI.skeletonmainwindow.repaint();
		}
		if (action.equals("menuexit")) {
			System.out.println("exit");
			try {
				System.exit(0);
			} catch (SecurityException err) {
				System.out.println("can not exit");
			}
		}
	}
}

class mouselisc implements MouseListener {
	public void mouseClicked(MouseEvent e) {
		int x = e.getX();
		int y = e.getY();

		System.out.println("mouse clicked at " + x + "," + y + "\n");
	}

	public void mouseEntered(MouseEvent e) {
		System.out.println("mouse entered \n");

	}

	public void mouseExited(MouseEvent e) {
		System.out.println("mouse exited \n");

	}

	public void mousePressed(MouseEvent e) {
		int x = e.getX();
		int y = e.getY();
		int b = e.getButton();

		if (b == MouseEvent.BUTTON1) {
			System.out.println("left mouse button pressed at " + x + "," + y
					+ "\n");
		}
		if (b == MouseEvent.BUTTON2) {
			System.out.println("middle mouse button pressed at " + x + "," + y
					+ "\n");
		}
		if (b == MouseEvent.BUTTON3) {
			System.out.println("right mouse button pressed at " + x + "," + y
					+ "\n");
		}
	}

	public void mouseReleased(MouseEvent e) {
		int x = e.getX();
		int y = e.getY();
		int b = e.getButton();

		if (b == MouseEvent.BUTTON1) {
			System.out.println("left mouse button released at " + x + "," + y
					+ "\n");
		}
		if (b == MouseEvent.BUTTON2) {
			System.out.println("middle mouse button released at " + x + "," + y
					+ "\n");
		}
		if (b == MouseEvent.BUTTON3) {
			System.out.println("right mouse button released at " + x + "," + y
					+ "\n");
		}

	}
}

class keylisc implements KeyListener {
	public void keyPressed(KeyEvent e) {
		int c = e.getKeyCode();
		char ch = e.getKeyChar();
		String s = e.getKeyText(c);
		System.out.println("key pressed, key code is " + c + "\n");
		if (e.isControlDown()) {
			if (s.equals("O")) {
				FileDialog fd = new FileDialog(PokerGUI.skeletonwindowframe,
						"open", FileDialog.LOAD);
				fd.show();
				String filename = fd.getDirectory() + fd.getFile();
				if (fd.getFile() != null) {
					try {
						// code that opens a file goes here
					} catch (Exception err) {
						System.out.println(err.getMessage());
					}
				}
				PokerGUI.skeletonwindowframe.requestFocusInWindow();
				PokerGUI.skeletonmainwindow.repaint();

			}
			if (s.equals("S")) {
				FileDialog fd = new FileDialog(PokerGUI.skeletonwindowframe,
						"save", FileDialog.LOAD);
				fd.show();
				String filename = fd.getDirectory() + fd.getFile();
				if (fd.getFile() != null) {
					try {
						// code that saves a file goes here
					} catch (Exception err) {
						System.out.println(err.getMessage());
					}
				}
				PokerGUI.skeletonwindowframe.requestFocusInWindow();
				PokerGUI.skeletonmainwindow.repaint();
			}
		}
	}

	public void keyReleased(KeyEvent e) {
		int c = e.getKeyCode();
		System.out.println("key released, key code is " + c + "\n");
	}

	public void keyTyped(KeyEvent e) {
		char c = e.getKeyChar();
		System.out.println("key typed, character is " + c + "\n");
	}
}

class skeletonmainwindowc extends JPanel {
	skeletonmainwindowc() {
	}

	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		// code that paints the main window goes here
	}
}

class PokerGUI {
	static keylisc keylis;
	static mouselisc mouselis;
	static actlisc actlis;
	static winlisc winlis;
	static skeletonmainwindowc skeletonmainwindow;
	static JFrame skeletonwindowframe;
	static JLabel statusbar;

	// the name of your program goes here
	static String programname = "skeleton app ";

	// the program version goes here
	static double programversion = 0.0;

	public static void main(String[] args) {
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				keylis = new keylisc();
				mouselis = new mouselisc();
				actlis = new actlisc();
				winlis = new winlisc();
				JMenuBar mb = new JMenuBar();

				JMenu m = new JMenu("file");
				mb.add(m);
				JMenuItem minew = new JMenuItem("new");
				m.add(minew);
				minew.setActionCommand("menunew");
				minew.addActionListener(PokerGUI.actlis);

				JMenuItem miopen = new JMenuItem("open");
				m.add(miopen);
				miopen.setActionCommand("menuopen");
				miopen.addActionListener(PokerGUI.actlis);

				JMenuItem misave = new JMenuItem("save");
				m.add(misave);
				misave.setActionCommand("menusave");
				misave.addActionListener(PokerGUI.actlis);

				JMenuItem miexit = new JMenuItem("exit");
				m.add(miexit);
				miexit.setActionCommand("menuexit");
				miexit.addActionListener(PokerGUI.actlis);

				SpringLayout spl = new SpringLayout();
				skeletonmainwindow = new skeletonmainwindowc();
				skeletonwindowframe = new JFrame();
				skeletonwindowframe.addWindowListener(winlis);
				skeletonwindowframe.setJMenuBar(mb);
				skeletonwindowframe.setBounds(0, 0, 600, 600);
				skeletonwindowframe.getContentPane().setLayout(spl);
				spl.putConstraint(SpringLayout.EAST, skeletonmainwindow, 0,
						SpringLayout.EAST, skeletonwindowframe.getContentPane());
				spl.putConstraint(SpringLayout.WEST, skeletonmainwindow, 0,
						SpringLayout.WEST, skeletonwindowframe.getContentPane());

				statusbar = new JLabel("status bar");
				spl.putConstraint(SpringLayout.SOUTH, statusbar, 0,
						SpringLayout.SOUTH,
						skeletonwindowframe.getContentPane());
				spl.putConstraint(SpringLayout.SOUTH, skeletonmainwindow, 0,
						SpringLayout.NORTH, statusbar);
				spl.putConstraint(SpringLayout.NORTH, skeletonmainwindow, 0,
						SpringLayout.NORTH,
						skeletonwindowframe.getContentPane());
				skeletonwindowframe.getContentPane().add(statusbar);
				skeletonwindowframe.getContentPane().add(skeletonmainwindow);
				skeletonwindowframe.setVisible(true);
				skeletonwindowframe.addKeyListener(keylis);
				skeletonmainwindow.addMouseListener(mouselis);
				skeletonwindowframe.setTitle(programname + "  v "
						+ programversion);
				PokerGUI.skeletonwindowframe.requestFocusInWindow();
			}
		});
	}
}
