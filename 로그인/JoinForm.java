package �α���;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.*;
import java.nio.*;
import java.nio.channels.SocketChannel;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.*;
import javax.swing.border.Border;

public class JoinForm extends JFrame  {
	private	String driver = "com.mysql.jdbc.Driver";
	private String url = "jdbc:mysql://localhost:3306/survey";
	private Connection con = null;
	private PreparedStatement pstmt = null;
	private Login log;
	private String sql;

	private Statement stmt;
	private JLabel ID;
	private JLabel Password;
	private JLabel rePassword;
	private JLabel Sex;
	private JLabel Grade;
	private JLabel Class1;
	// private JLabel dash;
	private JTextField txtID;
	private JPasswordField txtPassword;
	private JPasswordField txtrePassword;
	private JTextField txtSex;
	private JTextField txtGrade;
	private JComboBox<String> combo;

	private String User_ID;
	private String User_Password;
	private String User_rePassword;
	private String User_Sex;
	private String User_Grade;
	private String User_Class;

	private JButton join_mb_btn;
	private JButton join_mb_cancle;

	private JComboBox<String> comboSex;
	private String sex[] = { "��", "��"};

	private JComboBox<String> comboGrade;
	private String grade[] = { "1�г�", "2�г�", "3�г�", "4�г�"};

	private JComboBox<String> comboClass;
	private String classes[] = { "��ȣ����", "��������", "���������к�", "���������д���", "�������", "��ȸ���д���", "�������", "��Ȱ���д���", "��������",
			"�ι�����", "�ǰ�����", "�ڿ����д���", "ġ������" };
	
	

	public JoinForm() {
		super("ȸ������");
		this.init();
		this.setResizable(false);
		Toolkit tk = Toolkit.getDefaultToolkit();
		Dimension di = tk.getScreenSize();
		Dimension di1 = this.getSize();
		this.setLocation((int) (di.getWidth() / 2 - di1.getWidth() / 2),
				(int) (di.getHeight() / 2 - di1.getHeight() / 2));
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(500, 400);
		this.setVisible(true);
	}

	public void init() {
		JPanel pMain = new JPanel();
		JPanel pSub2 = new JPanel();
		JPanel pSub3 = new JPanel();
		JPanel pSub4 = new JPanel();

		JLabel join = new JLabel("ȸ������", JLabel.CENTER);
		join.setFont(new Font("����", Font.BOLD, 20));

		Canvas can = new Canvas();
		can.setBackground(Color.DARK_GRAY);
		can.setSize(1, 3);

		ID = new JLabel("���̵�         ", JLabel.RIGHT);
		Password = new JLabel("�н�����         ", JLabel.RIGHT);
		rePassword = new JLabel("�н����� ���Է�         ", JLabel.RIGHT);
		Sex = new JLabel("����         ", JLabel.RIGHT);
		Grade = new JLabel("�г�         ", JLabel.RIGHT);
		Class1 = new JLabel("�ܰ���         ", JLabel.RIGHT);
		// dash = new JLabel("-", JLabel.RIGHT);
		txtID = new JTextField("", 20);
		txtPassword = new JPasswordField("", 20);
		txtrePassword = new JPasswordField("", 20);
		comboSex = new JComboBox<String>(sex);
		comboGrade = new JComboBox<String>(grade);
		comboClass = new JComboBox<String>(classes);
		
		Container contentPane = this.getContentPane();

		pMain.setLayout(new BorderLayout());
		contentPane.add(pMain);

		pMain.add(pSub4, BorderLayout.CENTER);
		pSub4.setLayout(new BorderLayout());
		pSub4.add(pSub2, BorderLayout.CENTER);
		pSub2.setLayout(new GridBagLayout());
		Border bSub1 = BorderFactory.createTitledBorder("ȸ�� ������ ���� �Է�");
		pSub2.setBorder(bSub1);
		GridBagConstraints gbc = new GridBagConstraints();
		gbc.gridwidth = 1;
		gbc.gridheight = 1;
		gbc.gridx = 0;
		gbc.gridy = 0;
		gbc.fill = GridBagConstraints.HORIZONTAL;
		pSub2.add(ID, gbc);
		gbc.gridx = 1;
		pSub2.add(txtID, gbc);
		gbc.gridx = 0;
		gbc.gridy = 1;
		pSub2.add(Password, gbc);
		gbc.gridx = 1;
		pSub2.add(txtPassword, gbc);
		gbc.gridx = 0;
		gbc.gridy++;
		pSub2.add(rePassword, gbc);
		gbc.gridx = 1;
		pSub2.add(txtrePassword, gbc);
		gbc.gridx = 0;
		gbc.gridy++;
		pSub2.add(Sex, gbc);
		gbc.gridx = 1;
		pSub2.add(comboSex, gbc);
		gbc.gridx = 0;
		gbc.gridy++;
		pSub2.add(Grade, gbc);
		gbc.gridx = 1;
		pSub2.add(comboGrade, gbc);
		gbc.gridx = 0;
		gbc.gridy++;
		pSub2.add(Class1, gbc);
		gbc.gridx = 1;
		pSub2.add(comboClass, gbc);

		join_mb_btn = new JButton("ȸ������");
		join_mb_cancle = new JButton("���");
		join_mb_btn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				User_ID = txtID.getText();
				User_Password = txtPassword.getText();
				User_rePassword = txtrePassword.getText();
				User_Sex = comboSex.getSelectedItem().toString();
				User_Grade = comboGrade.getSelectedItem().toString();
				User_Class = comboClass.getSelectedItem().toString();

				translate trans = new translate(User_ID,User_Password,User_Sex,User_Grade,User_Class);
				User_Sex=trans.getUser_Sex();
				User_Grade=trans.getUser_Grade();
				User_Class=trans.getUser_Class();
				if (!User_Password.equals(User_rePassword)) {
					JOptionPane.showMessageDialog(null, "��й�ȣ�� ��ġ���� �ʽ��ϴ�.", "����", JOptionPane.ERROR_MESSAGE);
				}
				else if (User_ID.equals("") || User_Password.equals("") || User_rePassword.equals("") || User_Sex.equals("")
						|| User_Grade.equals("") || User_Class.equals("")) {
					JOptionPane.showMessageDialog(null, "�Է������� ������� �ʽ��ϴ�..", "����", JOptionPane.ERROR_MESSAGE);
				}
				else { memberInsert();
						try {
							Create_UserTable(User_ID);
						} catch (ClassNotFoundException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}}
				dispose();
			}});
		join_mb_cancle.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				dispose();
			}
		});
		pSub4.add(pSub3, BorderLayout.SOUTH);
		pSub3.setLayout(new FlowLayout());
		Border bSub2 = BorderFactory.createTitledBorder("");
		pSub3.setBorder(bSub2);
		pSub3.add(join_mb_btn);
		pSub3.add(join_mb_cancle);
	}
	public void memberInsert() {
		try {
			Class.forName(driver);
			con = DriverManager.getConnection(url, "root", "apmsetup");
				sql = "INSERT into student_info (User_ID,User_Password,Sex,Grade,Class) values (?,?,?,?,?)";

				pstmt = con.prepareStatement(sql);

		
				pstmt.setString(1, User_ID);
				pstmt.setString(2, User_Password);
				pstmt.setString(3, User_Sex);
				pstmt.setString(4, User_Grade);
				pstmt.setString(5, User_Class);
				
				
				int result = pstmt.executeUpdate();
				
				if (result == 1) {
					JOptionPane.showMessageDialog(this, "ȸ������ ���� ");
					log.setSize(300,200);
					
				} else {
					JOptionPane.showMessageDialog(this, "ȸ������ ���� ");
				}
	
			
		} catch (Exception e) {
		} finally {
			try {
				if (pstmt != null)
					pstmt.close();
				if (con != null)
					con.close();
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
	}

	public void Create_UserTable(String User_ID) throws ClassNotFoundException {
	// TODO Auto-generated constructor stub
	try {
		Class.forName(driver);
		con = DriverManager.getConnection(url, "root", "apmsetup");
	    stmt = con.createStatement();
	    sql = "CREATE TABLE "+User_ID+" ( " +
	        "TEST_NUM VARCHAR(10) NOT NULL," +
	        "TEST_DATE VARCHAR(10) NOT NULL, " +
	        "total TINYINT(12) NOT NULL)";
	    stmt.executeUpdate(sql);
	} catch (SQLException e) {
	    // TODO Auto-generated catch block
	    e.printStackTrace();
	}
}
}

