package 로그인;

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
	private String sex[] = { "남", "여"};

	private JComboBox<String> comboGrade;
	private String grade[] = { "1학년", "2학년", "3학년", "4학년"};

	private JComboBox<String> comboClass;
	private String classes[] = { "간호대학", "공과대학", "공공인재학부", "농업생명과학대학", "사범대학", "사회과학대학", "상과대학", "생활과학대학", "예술대학",
			"인문대학", "의과대학", "자연과학대학", "치과대학" };
	
	

	public JoinForm() {
		super("회원가입");
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

		JLabel join = new JLabel("회원가입", JLabel.CENTER);
		join.setFont(new Font("굴림", Font.BOLD, 20));

		Canvas can = new Canvas();
		can.setBackground(Color.DARK_GRAY);
		can.setSize(1, 3);

		ID = new JLabel("아이디         ", JLabel.RIGHT);
		Password = new JLabel("패스워드         ", JLabel.RIGHT);
		rePassword = new JLabel("패스워드 재입력         ", JLabel.RIGHT);
		Sex = new JLabel("성별         ", JLabel.RIGHT);
		Grade = new JLabel("학년         ", JLabel.RIGHT);
		Class1 = new JLabel("단과대         ", JLabel.RIGHT);
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
		Border bSub1 = BorderFactory.createTitledBorder("회원 가입을 위한 입력");
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

		join_mb_btn = new JButton("회원가입");
		join_mb_cancle = new JButton("취소");
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
					JOptionPane.showMessageDialog(null, "비밀번호가 일치하지 않습니다.", "오류", JOptionPane.ERROR_MESSAGE);
				}
				else if (User_ID.equals("") || User_Password.equals("") || User_rePassword.equals("") || User_Sex.equals("")
						|| User_Grade.equals("") || User_Class.equals("")) {
					JOptionPane.showMessageDialog(null, "입력정보가 충분하지 않습니다..", "오류", JOptionPane.ERROR_MESSAGE);
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
					JOptionPane.showMessageDialog(this, "회원가입 성공 ");
					log.setSize(300,200);
					
				} else {
					JOptionPane.showMessageDialog(this, "회원가입 실패 ");
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

