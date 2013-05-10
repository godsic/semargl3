#pragma once
#include "n_data.h"
#include "n_reader.h"
#include "n_probe.h"

#include "m_settings.h"
#include "m_image.h"
#include "m_sample.h"


#include < stdio.h >
#include < stdlib.h >
#include <vcclr.h>

#if _MSC_VER > 1499 // Visual C++ 2008 only
#include <msclr/marshal.h>
using namespace msclr::interop;
#endif 

namespace semargl3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;


	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripProgressBar^  toolStripProgressBar1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox2;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox9;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox10;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox11;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox12;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::GroupBox^  groupBox4;


	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox13;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::TabPage^  tabPage7;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox14;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::Label^  label27;

	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox15;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox18;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox17;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox16;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::ListBox^  listBox2;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox19;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::ListBox^  listBox3;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::TabPage^  tabPage2;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::GroupBox^  groupBox8;
private: System::Windows::Forms::RadioButton^  radioButton9;
private: System::Windows::Forms::RadioButton^  radioButton6;
private: System::Windows::Forms::RadioButton^  radioButton5;
private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::ListBox^  listBox4;
private: System::Windows::Forms::GroupBox^  groupBox10;
private: System::Windows::Forms::Button^  button3;


private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox20;
private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox22;
private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox21;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox25;
private: System::Windows::Forms::Label^  label58;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox24;
private: System::Windows::Forms::Label^  label57;
private: System::Windows::Forms::Label^  label56;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox23;
private: System::Windows::Forms::Label^  label55;
private: System::Windows::Forms::NumericUpDown^  numericUpDown6;
private: System::Windows::Forms::Label^  label54;
private: System::Windows::Forms::NumericUpDown^  numericUpDown5;
private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::GroupBox^  groupBox11;
private: System::Windows::Forms::PictureBox^  pictureBox2;





private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Panel^  panel1;


private: System::Windows::Forms::Label^  label62;
private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::Label^  label60;
private: System::Windows::Forms::Label^  label59;
private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::PictureBox^  pictureBox3;
private: System::Windows::Forms::ListBox^  listBox5;
private: System::Windows::Forms::ListBox^  listBox6;
private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::Label^  label64;
private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::Label^  label67;
private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::TabPage^  tabPage8;
private: System::Windows::Forms::Label^  label68;
private: System::Windows::Forms::Label^  label69;
private: System::Windows::Forms::Label^  label70;
private: System::Windows::Forms::Label^  label71;
private: System::Windows::Forms::Label^  label72;
private: System::Windows::Forms::Label^  label73;
private: System::Windows::Forms::Label^  label74;
private: System::Windows::Forms::Label^  label75;
private: System::Windows::Forms::Panel^  panel3;
private: System::Windows::Forms::PictureBox^  pictureBox6;
private: System::Windows::Forms::Panel^  panel4;
private: System::Windows::Forms::PictureBox^  pictureBox7;
private: System::Windows::Forms::Button^  button10;
private: System::Windows::Forms::Button^  button11;
private: System::Windows::Forms::Button^  button12;
private: System::Windows::Forms::Button^  button13;
private: System::Windows::Forms::PictureBox^  pictureBox4;
private: System::Windows::Forms::PictureBox^  pictureBox5;
private: System::Windows::Forms::GroupBox^  groupBox12;
private: System::Windows::Forms::ListBox^  listBox7;
private: System::Windows::Forms::GroupBox^  groupBox13;
private: System::Windows::Forms::ListBox^  listBox8;
private: System::Windows::Forms::GroupBox^  groupBox14;
private: System::Windows::Forms::NumericUpDown^  numericUpDown7;
private: System::Windows::Forms::Label^  label77;
private: System::Windows::Forms::Label^  label76;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox26;
private: System::Windows::Forms::Label^  label79;
private: System::Windows::Forms::Label^  label78;
private: System::Windows::Forms::Button^  button14;
private: System::Windows::Forms::GroupBox^  groupBox15;
private: System::Windows::Forms::ListBox^  listBox9;
private: System::Windows::Forms::Button^  button15;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox27;
private: System::Windows::Forms::Label^  label82;
private: System::Windows::Forms::Label^  label83;
private: System::Windows::Forms::NumericUpDown^  numericUpDown8;
private: System::Windows::Forms::Label^  label80;
private: System::Windows::Forms::Label^  label81;
private: System::Windows::Forms::GroupBox^  groupBox16;
private: System::Windows::Forms::ListBox^  listBox11;
private: System::Windows::Forms::ListBox^  listBox10;
private: System::Windows::Forms::Button^  button16;
private: System::Windows::Forms::Label^  label85;
private: System::Windows::Forms::Label^  label86;
private: System::Windows::Forms::Label^  label87;
private: System::Windows::Forms::Panel^  panel5;
private: System::Windows::Forms::PictureBox^  pictureBox8;
private: System::Windows::Forms::Button^  button17;
private: System::Windows::Forms::GroupBox^  groupBox17;
private: System::Windows::Forms::ListBox^  listBox12;
private: System::Windows::Forms::GroupBox^  groupBox18;
private: System::Windows::Forms::ListBox^  listBox13;
private: System::Windows::Forms::Button^  button18;
private: System::Windows::Forms::GroupBox^  groupBox19;
private: System::Windows::Forms::Label^  label89;
private: System::Windows::Forms::Label^  label88;
private: System::Windows::Forms::Label^  label84;
private: System::Windows::Forms::GroupBox^  groupBox20;
private: System::Windows::Forms::ListBox^  listBox14;
private: System::Windows::Forms::ListBox^  listBox16;
private: System::Windows::Forms::ListBox^  listBox15;
private: System::Windows::Forms::GroupBox^  groupBox21;
private: System::Windows::Forms::ListBox^  listBox17;
private: System::Windows::Forms::ListBox^  listBox18;
private: System::Windows::Forms::ListBox^  listBox19;
private: System::Windows::Forms::GroupBox^  groupBox22;
private: System::Windows::Forms::Label^  label90;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox28;
private: System::Windows::Forms::Label^  label92;
private: System::Windows::Forms::Label^  label93;
private: System::Windows::Forms::Label^  label91;
private: System::Windows::Forms::NumericUpDown^  numericUpDown9;
private: System::Windows::Forms::Label^  label94;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox29;
private: System::Windows::Forms::Label^  label95;
private: System::Windows::Forms::Label^  label96;
private: System::Windows::Forms::Label^  label97;
private: System::Windows::Forms::NumericUpDown^  numericUpDown10;
private: System::Windows::Forms::Label^  label98;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox30;
private: System::Windows::Forms::Label^  label99;
private: System::Windows::Forms::Label^  label100;
private: System::Windows::Forms::Label^  label101;
private: System::Windows::Forms::NumericUpDown^  numericUpDown11;
private: System::Windows::Forms::Button^  button19;
private: System::Windows::Forms::Button^  button20;
private: System::Windows::Forms::GroupBox^  groupBox23;
private: System::Windows::Forms::ListBox^  listBox20;
private: System::Windows::Forms::Button^  button21;
private: System::Windows::Forms::PictureBox^  pictureBox9;
private: System::Windows::Forms::Label^  label102;
private: System::Windows::Forms::Button^  button22;
private: System::Windows::Forms::LinkLabel^  linkLabel1;
private: System::Windows::Forms::TrackBar^  trackBar1;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Label^  label103;
private: System::Windows::Forms::Label^  label104;
private: System::Windows::Forms::Label^  label105;
private: System::Windows::Forms::TrackBar^  trackBar2;
private: System::Windows::Forms::Label^  label106;
private: System::Windows::Forms::Label^  label107;
private: System::Windows::Forms::TrackBar^  trackBar3;
private: System::Windows::Forms::Label^  label108;
private: System::Windows::Forms::Label^  label109;
private: System::Windows::Forms::ListBox^  listBox21;
private: System::Windows::Forms::Label^  label111;
private: System::Windows::Forms::Label^  label110;
private: System::Windows::Forms::CheckBox^  checkBox2;
private: System::Windows::Forms::GroupBox^  groupBox24;
private: System::Windows::Forms::GroupBox^  groupBox25;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox34;
private: System::Windows::Forms::Label^  label121;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox35;
private: System::Windows::Forms::Label^  label122;
private: System::Windows::Forms::Label^  label123;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox36;
private: System::Windows::Forms::Label^  label124;
private: System::Windows::Forms::NumericUpDown^  numericUpDown15;
private: System::Windows::Forms::Label^  label125;
private: System::Windows::Forms::NumericUpDown^  numericUpDown16;
private: System::Windows::Forms::Label^  label126;
private: System::Windows::Forms::Label^  label127;
private: System::Windows::Forms::Label^  label128;
private: System::Windows::Forms::NumericUpDown^  numericUpDown17;
private: System::Windows::Forms::Label^  label129;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox31;
private: System::Windows::Forms::Label^  label118;
private: System::Windows::Forms::Label^  label112;
private: System::Windows::Forms::Label^  label120;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox32;
private: System::Windows::Forms::NumericUpDown^  numericUpDown14;
private: System::Windows::Forms::Label^  label113;
private: System::Windows::Forms::Label^  label119;
private: System::Windows::Forms::Label^  label114;
private: System::Windows::Forms::Label^  label117;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox33;
private: System::Windows::Forms::NumericUpDown^  numericUpDown13;
private: System::Windows::Forms::Label^  label115;
private: System::Windows::Forms::Label^  label116;
private: System::Windows::Forms::NumericUpDown^  numericUpDown12;
private: System::Windows::Forms::RadioButton^  radioButton10;
private: System::Windows::Forms::GroupBox^  groupBox26;
private: System::Windows::Forms::RichTextBox^  richTextBox2;
private: System::Windows::Forms::Label^  label130;
private: System::Windows::Forms::ListBox^  listBox22;
private: System::Windows::Forms::GroupBox^  groupBox27;
private: System::Windows::Forms::Label^  label131;
private: System::Windows::Forms::ListBox^  listBox25;
private: System::Windows::Forms::ListBox^  listBox24;
private: System::Windows::Forms::ListBox^  listBox23;
private: System::Windows::Forms::Label^  label133;
private: System::Windows::Forms::Label^  label132;
private: System::Windows::Forms::GroupBox^  groupBox28;
private: System::Windows::Forms::RichTextBox^  richTextBox3;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
















	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->maskedTextBox9 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox10 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox11 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox12 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox8 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox5 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox7 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox4 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox13 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox6 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox19 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			this->maskedTextBox18 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox17 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox16 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox15 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox25 = (gcnew System::Windows::Forms::GroupBox());
			this->maskedTextBox34 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label121 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox35 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label122 = (gcnew System::Windows::Forms::Label());
			this->label123 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox36 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label124 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown15 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label125 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown16 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label126 = (gcnew System::Windows::Forms::Label());
			this->label127 = (gcnew System::Windows::Forms::Label());
			this->label128 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown17 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label129 = (gcnew System::Windows::Forms::Label());
			this->groupBox24 = (gcnew System::Windows::Forms::GroupBox());
			this->maskedTextBox31 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label118 = (gcnew System::Windows::Forms::Label());
			this->label112 = (gcnew System::Windows::Forms::Label());
			this->label120 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox32 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->numericUpDown14 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label113 = (gcnew System::Windows::Forms::Label());
			this->label119 = (gcnew System::Windows::Forms::Label());
			this->label114 = (gcnew System::Windows::Forms::Label());
			this->label117 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox33 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->numericUpDown13 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label115 = (gcnew System::Windows::Forms::Label());
			this->label116 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown12 = (gcnew System::Windows::Forms::NumericUpDown());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->maskedTextBox25 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox22 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox24 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox21 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox23 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox20 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->numericUpDown6 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label130 = (gcnew System::Windows::Forms::Label());
			this->listBox22 = (gcnew System::Windows::Forms::ListBox());
			this->label106 = (gcnew System::Windows::Forms::Label());
			this->label107 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label104 = (gcnew System::Windows::Forms::Label());
			this->label105 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox28 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox26 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label111 = (gcnew System::Windows::Forms::Label());
			this->label110 = (gcnew System::Windows::Forms::Label());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->groupBox14 = (gcnew System::Windows::Forms::GroupBox());
			this->maskedTextBox27 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->label83 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown8 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label80 = (gcnew System::Windows::Forms::Label());
			this->label81 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox26 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->numericUpDown7 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label79 = (gcnew System::Windows::Forms::Label());
			this->label77 = (gcnew System::Windows::Forms::Label());
			this->label78 = (gcnew System::Windows::Forms::Label());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox8 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox15 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox9 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox7 = (gcnew System::Windows::Forms::ListBox());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox27 = (gcnew System::Windows::Forms::GroupBox());
			this->label133 = (gcnew System::Windows::Forms::Label());
			this->label132 = (gcnew System::Windows::Forms::Label());
			this->label131 = (gcnew System::Windows::Forms::Label());
			this->listBox25 = (gcnew System::Windows::Forms::ListBox());
			this->listBox24 = (gcnew System::Windows::Forms::ListBox());
			this->listBox23 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox18 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox13 = (gcnew System::Windows::Forms::ListBox());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->groupBox17 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox12 = (gcnew System::Windows::Forms::ListBox());
			this->label85 = (gcnew System::Windows::Forms::Label());
			this->label86 = (gcnew System::Windows::Forms::Label());
			this->label87 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->groupBox16 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox11 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->label109 = (gcnew System::Windows::Forms::Label());
			this->listBox21 = (gcnew System::Windows::Forms::ListBox());
			this->label108 = (gcnew System::Windows::Forms::Label());
			this->label103 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->label102 = (gcnew System::Windows::Forms::Label());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox19 = (gcnew System::Windows::Forms::GroupBox());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->groupBox23 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox20 = (gcnew System::Windows::Forms::ListBox());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->groupBox22 = (gcnew System::Windows::Forms::GroupBox());
			this->label98 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox30 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label99 = (gcnew System::Windows::Forms::Label());
			this->label100 = (gcnew System::Windows::Forms::Label());
			this->label101 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown11 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label94 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox29 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label95 = (gcnew System::Windows::Forms::Label());
			this->label96 = (gcnew System::Windows::Forms::Label());
			this->label97 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown10 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label90 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox28 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label92 = (gcnew System::Windows::Forms::Label());
			this->label93 = (gcnew System::Windows::Forms::Label());
			this->label91 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown9 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox21 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox17 = (gcnew System::Windows::Forms::ListBox());
			this->listBox18 = (gcnew System::Windows::Forms::ListBox());
			this->listBox19 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox20 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox16 = (gcnew System::Windows::Forms::ListBox());
			this->listBox15 = (gcnew System::Windows::Forms::ListBox());
			this->listBox14 = (gcnew System::Windows::Forms::ListBox());
			this->label89 = (gcnew System::Windows::Forms::Label());
			this->label88 = (gcnew System::Windows::Forms::Label());
			this->label84 = (gcnew System::Windows::Forms::Label());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->maskedTextBox14 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->listBox10 = (gcnew System::Windows::Forms::ListBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox25->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown17))->BeginInit();
			this->groupBox24->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown12))->BeginInit();
			this->groupBox10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->groupBox8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->groupBox11->SuspendLayout();
			this->tabPage8->SuspendLayout();
			this->groupBox28->SuspendLayout();
			this->groupBox26->SuspendLayout();
			this->groupBox14->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown7))->BeginInit();
			this->groupBox13->SuspendLayout();
			this->groupBox15->SuspendLayout();
			this->groupBox12->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
			this->tabPage4->SuspendLayout();
			this->groupBox27->SuspendLayout();
			this->groupBox18->SuspendLayout();
			this->groupBox17->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
			this->groupBox16->SuspendLayout();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->BeginInit();
			this->groupBox19->SuspendLayout();
			this->groupBox23->SuspendLayout();
			this->groupBox22->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown9))->BeginInit();
			this->groupBox21->SuspendLayout();
			this->groupBox20->SuspendLayout();
			this->tabPage7->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(1222, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(22, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage8);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tabControl1->ItemSize = System::Drawing::Size(64, 64);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1232, 640);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->checkBox2);
			this->tabPage1->Controls->Add(this->groupBox4);
			this->tabPage1->Controls->Add(this->groupBox3);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->toolStrip1);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tabPage1->Location = System::Drawing::Point(4, 68);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1224, 568);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"File and Info";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(412, 118);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(286, 20);
			this->checkBox2->TabIndex = 4;
			this->checkBox2->Text = L"Extract the path to the data from the static file";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox4->Controls->Add(this->listBox1);
			this->groupBox4->Controls->Add(this->checkBox1);
			this->groupBox4->Controls->Add(this->radioButton7);
			this->groupBox4->Controls->Add(this->radioButton8);
			this->groupBox4->Controls->Add(this->label26);
			this->groupBox4->Location = System::Drawing::Point(3, 158);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(1215, 58);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Pre-processing method";
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"0.0"});
			this->listBox1->Location = System::Drawing::Point(680, 28);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(489, 20);
			this->listBox1->TabIndex = 2;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(328, 28);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(267, 20);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"Normalize by magnetization of saturation";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// radioButton7
			// 
			this->radioButton7->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton7->AutoSize = true;
			this->radioButton7->Checked = true;
			this->radioButton7->FlatAppearance->CheckedBackColor = System::Drawing::Color::DodgerBlue;
			this->radioButton7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton7->Location = System::Drawing::Point(73, 24);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(189, 28);
			this->radioButton7->TabIndex = 0;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"Substrat static magnetization";
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// radioButton8
			// 
			this->radioButton8->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton8->AutoSize = true;
			this->radioButton8->FlatAppearance->CheckedBackColor = System::Drawing::Color::DodgerBlue;
			this->radioButton8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton8->Location = System::Drawing::Point(6, 24);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(66, 28);
			this->radioButton8->TabIndex = 0;
			this->radioButton8->Text = L"Bypass";
			this->radioButton8->UseVisualStyleBackColor = true;
			// 
			// label26
			// 
			this->label26->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(1172, 29);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(32, 16);
			this->label26->TabIndex = 4;
			this->label26->Text = L"A/m";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->radioButton10);
			this->groupBox3->Controls->Add(this->radioButton4);
			this->groupBox3->Controls->Add(this->radioButton3);
			this->groupBox3->Controls->Add(this->radioButton2);
			this->groupBox3->Controls->Add(this->radioButton1);
			this->groupBox3->Location = System::Drawing::Point(6, 94);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(400, 58);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Component of the magnetization to be analysed";
			// 
			// radioButton10
			// 
			this->radioButton10->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton10->AutoSize = true;
			this->radioButton10->FlatAppearance->CheckedBackColor = System::Drawing::Color::DodgerBlue;
			this->radioButton10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton10->Location = System::Drawing::Point(191, 25);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(80, 28);
			this->radioButton10->TabIndex = 1;
			this->radioButton10->Text = L"div(M)/4Pi";
			this->radioButton10->UseVisualStyleBackColor = true;
			this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton10_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton4->AutoSize = true;
			this->radioButton4->FlatAppearance->CheckedBackColor = System::Drawing::Color::DodgerBlue;
			this->radioButton4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton4->Location = System::Drawing::Point(137, 25);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(49, 28);
			this->radioButton4->TabIndex = 0;
			this->radioButton4->Text = L"Minp";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton4_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton3->AutoSize = true;
			this->radioButton3->FlatAppearance->CheckedBackColor = System::Drawing::Color::DodgerBlue;
			this->radioButton3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton3->Location = System::Drawing::Point(94, 25);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(37, 28);
			this->radioButton3->TabIndex = 0;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Mz";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton2->AutoSize = true;
			this->radioButton2->FlatAppearance->CheckedBackColor = System::Drawing::Color::DodgerBlue;
			this->radioButton2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton2->Location = System::Drawing::Point(50, 24);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(38, 28);
			this->radioButton2->TabIndex = 0;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"My";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->radioButton1->FlatAppearance->CheckedBackColor = System::Drawing::Color::DodgerBlue;
			this->radioButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton1->Location = System::Drawing::Point(6, 24);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(37, 28);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Mx";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox2->Controls->Add(this->label23);
			this->groupBox2->Controls->Add(this->richTextBox1);
			this->groupBox2->Controls->Add(this->maskedTextBox9);
			this->groupBox2->Controls->Add(this->label16);
			this->groupBox2->Controls->Add(this->maskedTextBox10);
			this->groupBox2->Controls->Add(this->label17);
			this->groupBox2->Controls->Add(this->maskedTextBox11);
			this->groupBox2->Controls->Add(this->label21);
			this->groupBox2->Controls->Add(this->label18);
			this->groupBox2->Controls->Add(this->label22);
			this->groupBox2->Controls->Add(this->label15);
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label25);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->label20);
			this->groupBox2->Controls->Add(this->label19);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->maskedTextBox12);
			this->groupBox2->Controls->Add(this->maskedTextBox8);
			this->groupBox2->Controls->Add(this->maskedTextBox5);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->maskedTextBox7);
			this->groupBox2->Controls->Add(this->maskedTextBox4);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->maskedTextBox13);
			this->groupBox2->Controls->Add(this->label24);
			this->groupBox2->Controls->Add(this->maskedTextBox6);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->maskedTextBox3);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Location = System::Drawing::Point(6, 313);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(1212, 263);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Simulations details";
			// 
			// label23
			// 
			this->label23->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(6, 219);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(31, 16);
			this->label23->TabIndex = 12;
			this->label23->Text = L"Log";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->BackColor = System::Drawing::SystemColors::Highlight;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::Color::Silver;
			this->richTextBox1->Location = System::Drawing::Point(6, 239);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(1200, 18);
			this->richTextBox1->TabIndex = 11;
			this->richTextBox1->Text = L"";
			// 
			// maskedTextBox9
			// 
			this->maskedTextBox9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maskedTextBox9->Location = System::Drawing::Point(170, 187);
			this->maskedTextBox9->Name = L"maskedTextBox9";
			this->maskedTextBox9->ReadOnly = true;
			this->maskedTextBox9->Size = System::Drawing::Size(1036, 22);
			this->maskedTextBox9->TabIndex = 8;
			this->maskedTextBox9->Text = L"data are not loaded yet.";
			this->maskedTextBox9->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(6, 190);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(122, 16);
			this->label16->TabIndex = 6;
			this->label16->Text = L"Reference .MIF file:";
			// 
			// maskedTextBox10
			// 
			this->maskedTextBox10->Location = System::Drawing::Point(193, 156);
			this->maskedTextBox10->Name = L"maskedTextBox10";
			this->maskedTextBox10->ReadOnly = true;
			this->maskedTextBox10->Size = System::Drawing::Size(93, 22);
			this->maskedTextBox10->TabIndex = 10;
			this->maskedTextBox10->Text = L"0";
			this->maskedTextBox10->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(6, 159);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(133, 16);
			this->label17->TabIndex = 5;
			this->label17->Text = L"Total simulation time:";
			// 
			// maskedTextBox11
			// 
			this->maskedTextBox11->Location = System::Drawing::Point(193, 125);
			this->maskedTextBox11->Name = L"maskedTextBox11";
			this->maskedTextBox11->ReadOnly = true;
			this->maskedTextBox11->Size = System::Drawing::Size(93, 22);
			this->maskedTextBox11->TabIndex = 9;
			this->maskedTextBox11->Text = L"0";
			this->maskedTextBox11->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(344, 128);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(169, 16);
			this->label21->TabIndex = 7;
			this->label21->Text = L"Magnetization of saturation:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(6, 128);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(138, 16);
			this->label18->TabIndex = 7;
			this->label18->Text = L"Stage simulation time:";
			// 
			// label22
			// 
			this->label22->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(1172, 128);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(32, 16);
			this->label22->TabIndex = 4;
			this->label22->Text = L"A/m";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(799, 83);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(19, 16);
			this->label15->TabIndex = 4;
			this->label15->Text = L"m";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(799, 52);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(19, 16);
			this->label14->TabIndex = 3;
			this->label14->Text = L"m";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(313, 83);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(61, 16);
			this->label10->TabIndex = 4;
			this->label10->Text = L"arb. units";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(1116, 21);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(61, 16);
			this->label25->TabIndex = 2;
			this->label25->Text = L"arb. units";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(799, 21);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(19, 16);
			this->label13->TabIndex = 2;
			this->label13->Text = L"m";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(292, 159);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(15, 16);
			this->label20->TabIndex = 3;
			this->label20->Text = L"s";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(292, 128);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(15, 16);
			this->label19->TabIndex = 2;
			this->label19->Text = L"s";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(313, 52);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(61, 16);
			this->label11->TabIndex = 3;
			this->label11->Text = L"arb. units";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(313, 21);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(61, 16);
			this->label12->TabIndex = 2;
			this->label12->Text = L"arb. units";
			// 
			// maskedTextBox12
			// 
			this->maskedTextBox12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maskedTextBox12->Location = System::Drawing::Point(581, 125);
			this->maskedTextBox12->Name = L"maskedTextBox12";
			this->maskedTextBox12->ReadOnly = true;
			this->maskedTextBox12->Size = System::Drawing::Size(585, 22);
			this->maskedTextBox12->TabIndex = 1;
			this->maskedTextBox12->Text = L"0";
			this->maskedTextBox12->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// maskedTextBox8
			// 
			this->maskedTextBox8->Location = System::Drawing::Point(700, 80);
			this->maskedTextBox8->Name = L"maskedTextBox8";
			this->maskedTextBox8->ReadOnly = true;
			this->maskedTextBox8->Size = System::Drawing::Size(93, 22);
			this->maskedTextBox8->TabIndex = 1;
			this->maskedTextBox8->Text = L"0";
			this->maskedTextBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// maskedTextBox5
			// 
			this->maskedTextBox5->Location = System::Drawing::Point(214, 80);
			this->maskedTextBox5->Name = L"maskedTextBox5";
			this->maskedTextBox5->ReadOnly = true;
			this->maskedTextBox5->Size = System::Drawing::Size(93, 22);
			this->maskedTextBox5->TabIndex = 1;
			this->maskedTextBox5->Text = L"0";
			this->maskedTextBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(536, 83);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(109, 16);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Cell size along Z:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 83);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(152, 16);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Number of cells along Z:";
			// 
			// maskedTextBox7
			// 
			this->maskedTextBox7->Location = System::Drawing::Point(700, 49);
			this->maskedTextBox7->Name = L"maskedTextBox7";
			this->maskedTextBox7->ReadOnly = true;
			this->maskedTextBox7->Size = System::Drawing::Size(93, 22);
			this->maskedTextBox7->TabIndex = 1;
			this->maskedTextBox7->Text = L"0";
			this->maskedTextBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// maskedTextBox4
			// 
			this->maskedTextBox4->Location = System::Drawing::Point(214, 49);
			this->maskedTextBox4->Name = L"maskedTextBox4";
			this->maskedTextBox4->ReadOnly = true;
			this->maskedTextBox4->Size = System::Drawing::Size(93, 22);
			this->maskedTextBox4->TabIndex = 1;
			this->maskedTextBox4->Text = L"0";
			this->maskedTextBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(536, 52);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(110, 16);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Cell size along Y:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 52);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(153, 16);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Number of cells along Y:";
			// 
			// maskedTextBox13
			// 
			this->maskedTextBox13->Location = System::Drawing::Point(1017, 18);
			this->maskedTextBox13->Name = L"maskedTextBox13";
			this->maskedTextBox13->ReadOnly = true;
			this->maskedTextBox13->Size = System::Drawing::Size(93, 22);
			this->maskedTextBox13->TabIndex = 1;
			this->maskedTextBox13->Text = L"0";
			this->maskedTextBox13->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(836, 21);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(137, 16);
			this->label24->TabIndex = 0;
			this->label24->Text = L"Number of time steps:";
			// 
			// maskedTextBox6
			// 
			this->maskedTextBox6->Location = System::Drawing::Point(700, 18);
			this->maskedTextBox6->Name = L"maskedTextBox6";
			this->maskedTextBox6->ReadOnly = true;
			this->maskedTextBox6->Size = System::Drawing::Size(93, 22);
			this->maskedTextBox6->TabIndex = 1;
			this->maskedTextBox6->Text = L"0";
			this->maskedTextBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(536, 21);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(109, 16);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Cell size along X:";
			// 
			// maskedTextBox3
			// 
			this->maskedTextBox3->Location = System::Drawing::Point(214, 18);
			this->maskedTextBox3->Name = L"maskedTextBox3";
			this->maskedTextBox3->ReadOnly = true;
			this->maskedTextBox3->Size = System::Drawing::Size(93, 22);
			this->maskedTextBox3->TabIndex = 1;
			this->maskedTextBox3->Text = L"0";
			this->maskedTextBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(152, 16);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Number of cells along X:";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->maskedTextBox2);
			this->groupBox1->Controls->Add(this->maskedTextBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(3, 231);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1215, 76);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"OMF data location";
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Lime;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(1089, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 57);
			this->button2->TabIndex = 2;
			this->button2->Text = L"GO";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maskedTextBox2->ForeColor = System::Drawing::Color::Blue;
			this->maskedTextBox2->Location = System::Drawing::Point(269, 44);
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->ReadOnly = true;
			this->maskedTextBox2->Size = System::Drawing::Size(814, 22);
			this->maskedTextBox2->TabIndex = 1;
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maskedTextBox1->ForeColor = System::Drawing::Color::Blue;
			this->maskedTextBox1->Location = System::Drawing::Point(269, 13);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->ReadOnly = true;
			this->maskedTextBox1->Size = System::Drawing::Size(814, 22);
			this->maskedTextBox1->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 52);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(195, 16);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Dynamic data containing folder:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Static file:";
			// 
			// toolStrip1
			// 
			this->toolStrip1->AutoSize = false;
			this->toolStrip1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(64, 64);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->toolStripButton1, 
				this->toolStripSeparator2, this->toolStripButton2, this->toolStripSeparator1, this->toolStripButton3, this->toolStripSeparator3, 
				this->toolStripButton4});
			this->toolStrip1->Location = System::Drawing::Point(3, 3);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1218, 89);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->BackColor = System::Drawing::Color::OrangeRed;
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton1->ForeColor = System::Drawing::Color::White;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(71, 86);
			this->toolStripButton1->Text = L"Static file";
			this->toolStripButton1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton1->ToolTipText = L"Please specify name of the ground state file which must have *.stc extension.";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->BackColor = System::Drawing::Color::OrangeRed;
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton2->ForeColor = System::Drawing::Color::White;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(128, 86);
			this->toolStripButton2->Text = L"Data folder picker";
			this->toolStripButton2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 89);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->BackColor = System::Drawing::Color::OrangeRed;
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton3->ForeColor = System::Drawing::Color::White;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(84, 86);
			this->toolStripButton3->Text = L"Load RAW";
			this->toolStripButton3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->BackColor = System::Drawing::Color::OrangeRed;
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton4->ForeColor = System::Drawing::Color::White;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(84, 86);
			this->toolStripButton4->Text = L"Save RAW";
			this->toolStripButton4->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &Form1::toolStripButton4_Click);
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->groupBox7);
			this->tabPage6->Controls->Add(this->groupBox6);
			this->tabPage6->Controls->Add(this->groupBox5);
			this->tabPage6->Location = System::Drawing::Point(4, 68);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(1224, 568);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Settings";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// groupBox7
			// 
			this->groupBox7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox7->Controls->Add(this->listBox3);
			this->groupBox7->Controls->Add(this->label38);
			this->groupBox7->Location = System::Drawing::Point(6, 381);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(805, 120);
			this->groupBox7->TabIndex = 8;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Image export settings";
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 16;
			this->listBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"TIFF", L"PNG", L"BMP"});
			this->listBox3->Location = System::Drawing::Point(265, 24);
			this->listBox3->MultiColumn = true;
			this->listBox3->Name = L"listBox3";
			this->listBox3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->listBox3->Size = System::Drawing::Size(129, 52);
			this->listBox3->TabIndex = 4;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(6, 24);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(128, 16);
			this->label38->TabIndex = 3;
			this->label38->Text = L"Image output format:";
			this->label38->Click += gcnew System::EventHandler(this, &Form1::label28_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox6->Controls->Add(this->listBox2);
			this->groupBox6->Controls->Add(this->label35);
			this->groupBox6->Controls->Add(this->maskedTextBox19);
			this->groupBox6->Controls->Add(this->label36);
			this->groupBox6->Controls->Add(this->label37);
			this->groupBox6->Location = System::Drawing::Point(6, 6);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(882, 142);
			this->groupBox6->TabIndex = 7;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Analysies settings";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 16;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"NONE / RECT", L"Welch", L"Keiser", L"Hamming"});
			this->listBox2->Location = System::Drawing::Point(265, 21);
			this->listBox2->MultiColumn = true;
			this->listBox2->Name = L"listBox2";
			this->listBox2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->listBox2->Size = System::Drawing::Size(190, 68);
			this->listBox2->TabIndex = 4;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox2_SelectedIndexChanged);
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(6, 21);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(202, 16);
			this->label35->TabIndex = 3;
			this->label35->Text = L"Time domaing FFT window type:";
			this->label35->Click += gcnew System::EventHandler(this, &Form1::label28_Click);
			// 
			// maskedTextBox19
			// 
			this->maskedTextBox19->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maskedTextBox19->Location = System::Drawing::Point(342, 100);
			this->maskedTextBox19->Name = L"maskedTextBox19";
			this->maskedTextBox19->Size = System::Drawing::Size(431, 22);
			this->maskedTextBox19->TabIndex = 6;
			this->maskedTextBox19->Text = L"3.0";
			this->maskedTextBox19->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox19_Validated);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(9, 103);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(239, 16);
			this->label36->TabIndex = 3;
			this->label36->Text = L"Value of the Keiser windows coefficient:";
			this->label36->Click += gcnew System::EventHandler(this, &Form1::label28_Click);
			// 
			// label37
			// 
			this->label37->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(779, 103);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(61, 16);
			this->label37->TabIndex = 5;
			this->label37->Text = L"arb. units";
			// 
			// groupBox5
			// 
			this->groupBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox5->Controls->Add(this->listBox6);
			this->groupBox5->Controls->Add(this->maskedTextBox18);
			this->groupBox5->Controls->Add(this->label63);
			this->groupBox5->Controls->Add(this->label34);
			this->groupBox5->Controls->Add(this->maskedTextBox17);
			this->groupBox5->Controls->Add(this->label32);
			this->groupBox5->Controls->Add(this->maskedTextBox16);
			this->groupBox5->Controls->Add(this->label33);
			this->groupBox5->Controls->Add(this->label30);
			this->groupBox5->Controls->Add(this->label31);
			this->groupBox5->Controls->Add(this->maskedTextBox15);
			this->groupBox5->Controls->Add(this->label29);
			this->groupBox5->Controls->Add(this->label27);
			this->groupBox5->Controls->Add(this->label28);
			this->groupBox5->Location = System::Drawing::Point(6, 154);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(882, 221);
			this->groupBox5->TabIndex = 0;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Text output settings";
			// 
			// listBox6
			// 
			this->listBox6->FormattingEnabled = true;
			this->listBox6->ItemHeight = 16;
			this->listBox6->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Amplitude and Phase", L"Complex"});
			this->listBox6->Location = System::Drawing::Point(262, 142);
			this->listBox6->MultiColumn = true;
			this->listBox6->Name = L"listBox6";
			this->listBox6->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->listBox6->Size = System::Drawing::Size(177, 52);
			this->listBox6->TabIndex = 4;
			this->listBox6->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox6_SelectedIndexChanged);
			// 
			// maskedTextBox18
			// 
			this->maskedTextBox18->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maskedTextBox18->Location = System::Drawing::Point(427, 111);
			this->maskedTextBox18->Name = L"maskedTextBox18";
			this->maskedTextBox18->Size = System::Drawing::Size(346, 22);
			this->maskedTextBox18->TabIndex = 6;
			this->maskedTextBox18->Text = L"0";
			this->maskedTextBox18->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox18_Validated);
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(9, 142);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(116, 16);
			this->label63->TabIndex = 3;
			this->label63->Text = L"Text output format:";
			this->label63->Click += gcnew System::EventHandler(this, &Form1::label28_Click);
			// 
			// label34
			// 
			this->label34->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(779, 111);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(44, 16);
			this->label34->TabIndex = 5;
			this->label34->Text = L"points";
			// 
			// maskedTextBox17
			// 
			this->maskedTextBox17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maskedTextBox17->Location = System::Drawing::Point(323, 80);
			this->maskedTextBox17->Name = L"maskedTextBox17";
			this->maskedTextBox17->Size = System::Drawing::Size(450, 22);
			this->maskedTextBox17->TabIndex = 6;
			this->maskedTextBox17->Text = L"0";
			this->maskedTextBox17->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox17_Validated);
			// 
			// label32
			// 
			this->label32->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(779, 80);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(44, 16);
			this->label32->TabIndex = 5;
			this->label32->Text = L"points";
			// 
			// maskedTextBox16
			// 
			this->maskedTextBox16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maskedTextBox16->Location = System::Drawing::Point(323, 49);
			this->maskedTextBox16->Name = L"maskedTextBox16";
			this->maskedTextBox16->Size = System::Drawing::Size(450, 22);
			this->maskedTextBox16->TabIndex = 6;
			this->maskedTextBox16->Text = L"0";
			this->maskedTextBox16->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox16_Validated);
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(6, 114);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(327, 16);
			this->label33->TabIndex = 3;
			this->label33->Text = L"Number of maximum points along time/frequency axis:";
			this->label33->Click += gcnew System::EventHandler(this, &Form1::label28_Click);
			// 
			// label30
			// 
			this->label30->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(779, 49);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(44, 16);
			this->label30->TabIndex = 5;
			this->label30->Text = L"points";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(6, 83);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(247, 16);
			this->label31->TabIndex = 3;
			this->label31->Text = L"Number of maximum points along Z axis:";
			this->label31->Click += gcnew System::EventHandler(this, &Form1::label28_Click);
			// 
			// maskedTextBox15
			// 
			this->maskedTextBox15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maskedTextBox15->Location = System::Drawing::Point(323, 18);
			this->maskedTextBox15->Name = L"maskedTextBox15";
			this->maskedTextBox15->Size = System::Drawing::Size(450, 22);
			this->maskedTextBox15->TabIndex = 6;
			this->maskedTextBox15->Text = L"0";
			this->maskedTextBox15->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox15_Validated);
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(6, 52);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(248, 16);
			this->label29->TabIndex = 3;
			this->label29->Text = L"Number of maximum points along Y axis:";
			this->label29->Click += gcnew System::EventHandler(this, &Form1::label28_Click);
			// 
			// label27
			// 
			this->label27->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(779, 21);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(44, 16);
			this->label27->TabIndex = 5;
			this->label27->Text = L"points";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(6, 21);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(247, 16);
			this->label28->TabIndex = 3;
			this->label28->Text = L"Number of maximum points along X axis:";
			this->label28->Click += gcnew System::EventHandler(this, &Form1::label28_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->groupBox9);
			this->tabPage2->Controls->Add(this->groupBox8);
			this->tabPage2->Controls->Add(this->pictureBox1);
			this->tabPage2->Controls->Add(this->label39);
			this->tabPage2->Location = System::Drawing::Point(4, 68);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1224, 568);
			this->tabPage2->TabIndex = 7;
			this->tabPage2->Text = L"Probe Configuration";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Leave += gcnew System::EventHandler(this, &Form1::tabPage2_Leave);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Lime;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(22, 27);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(134, 115);
			this->button3->TabIndex = 6;
			this->button3->Text = L"GENERATE";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// groupBox9
			// 
			this->groupBox9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox9->Controls->Add(this->groupBox25);
			this->groupBox9->Controls->Add(this->groupBox24);
			this->groupBox9->Controls->Add(this->listBox4);
			this->groupBox9->Controls->Add(this->groupBox10);
			this->groupBox9->Controls->Add(this->label40);
			this->groupBox9->Location = System::Drawing::Point(174, 6);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(1044, 303);
			this->groupBox9->TabIndex = 2;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Probe configuration";
			// 
			// groupBox25
			// 
			this->groupBox25->Controls->Add(this->maskedTextBox34);
			this->groupBox25->Controls->Add(this->label121);
			this->groupBox25->Controls->Add(this->maskedTextBox35);
			this->groupBox25->Controls->Add(this->label122);
			this->groupBox25->Controls->Add(this->label123);
			this->groupBox25->Controls->Add(this->maskedTextBox36);
			this->groupBox25->Controls->Add(this->label124);
			this->groupBox25->Controls->Add(this->numericUpDown15);
			this->groupBox25->Controls->Add(this->label125);
			this->groupBox25->Controls->Add(this->numericUpDown16);
			this->groupBox25->Controls->Add(this->label126);
			this->groupBox25->Controls->Add(this->label127);
			this->groupBox25->Controls->Add(this->label128);
			this->groupBox25->Controls->Add(this->numericUpDown17);
			this->groupBox25->Controls->Add(this->label129);
			this->groupBox25->Location = System::Drawing::Point(473, 163);
			this->groupBox25->Name = L"groupBox25";
			this->groupBox25->Size = System::Drawing::Size(481, 136);
			this->groupBox25->TabIndex = 7;
			this->groupBox25->TabStop = false;
			this->groupBox25->Text = L"Optical spot emulator";
			// 
			// maskedTextBox34
			// 
			this->maskedTextBox34->Location = System::Drawing::Point(274, 87);
			this->maskedTextBox34->Name = L"maskedTextBox34";
			this->maskedTextBox34->ReadOnly = true;
			this->maskedTextBox34->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox34->TabIndex = 16;
			this->maskedTextBox34->Text = L"0.0";
			// 
			// label121
			// 
			this->label121->AutoSize = true;
			this->label121->Location = System::Drawing::Point(380, 90);
			this->label121->Name = L"label121";
			this->label121->Size = System::Drawing::Size(19, 16);
			this->label121->TabIndex = 12;
			this->label121->Text = L"m";
			// 
			// maskedTextBox35
			// 
			this->maskedTextBox35->Location = System::Drawing::Point(274, 56);
			this->maskedTextBox35->Name = L"maskedTextBox35";
			this->maskedTextBox35->ReadOnly = true;
			this->maskedTextBox35->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox35->TabIndex = 18;
			this->maskedTextBox35->Text = L"0.0";
			// 
			// label122
			// 
			this->label122->AutoSize = true;
			this->label122->Location = System::Drawing::Point(380, 59);
			this->label122->Name = L"label122";
			this->label122->Size = System::Drawing::Size(19, 16);
			this->label122->TabIndex = 10;
			this->label122->Text = L"m";
			// 
			// label123
			// 
			this->label123->AutoSize = true;
			this->label123->Location = System::Drawing::Point(166, 89);
			this->label123->Name = L"label123";
			this->label123->Size = System::Drawing::Size(69, 16);
			this->label123->TabIndex = 13;
			this->label123->Text = L"-arb. units-";
			// 
			// maskedTextBox36
			// 
			this->maskedTextBox36->Location = System::Drawing::Point(274, 25);
			this->maskedTextBox36->Name = L"maskedTextBox36";
			this->maskedTextBox36->ReadOnly = true;
			this->maskedTextBox36->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox36->TabIndex = 17;
			this->maskedTextBox36->Text = L"0.0";
			// 
			// label124
			// 
			this->label124->AutoSize = true;
			this->label124->Location = System::Drawing::Point(166, 58);
			this->label124->Name = L"label124";
			this->label124->Size = System::Drawing::Size(69, 16);
			this->label124->TabIndex = 14;
			this->label124->Text = L"-arb. units-";
			// 
			// numericUpDown15
			// 
			this->numericUpDown15->Location = System::Drawing::Point(40, 87);
			this->numericUpDown15->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000000, 0, 0, 0});
			this->numericUpDown15->Name = L"numericUpDown15";
			this->numericUpDown15->Size = System::Drawing::Size(120, 22);
			this->numericUpDown15->TabIndex = 7;
			// 
			// label125
			// 
			this->label125->AutoSize = true;
			this->label125->Location = System::Drawing::Point(380, 28);
			this->label125->Name = L"label125";
			this->label125->Size = System::Drawing::Size(19, 16);
			this->label125->TabIndex = 15;
			this->label125->Text = L"m";
			// 
			// numericUpDown16
			// 
			this->numericUpDown16->Location = System::Drawing::Point(40, 56);
			this->numericUpDown16->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000000, 0, 0, 0});
			this->numericUpDown16->Name = L"numericUpDown16";
			this->numericUpDown16->Size = System::Drawing::Size(120, 22);
			this->numericUpDown16->TabIndex = 8;
			// 
			// label126
			// 
			this->label126->AutoSize = true;
			this->label126->Location = System::Drawing::Point(6, 89);
			this->label126->Name = L"label126";
			this->label126->Size = System::Drawing::Size(28, 16);
			this->label126->TabIndex = 5;
			this->label126->Text = L"YZ:";
			// 
			// label127
			// 
			this->label127->AutoSize = true;
			this->label127->Location = System::Drawing::Point(166, 27);
			this->label127->Name = L"label127";
			this->label127->Size = System::Drawing::Size(69, 16);
			this->label127->TabIndex = 11;
			this->label127->Text = L"-arb. units-";
			// 
			// label128
			// 
			this->label128->AutoSize = true;
			this->label128->Location = System::Drawing::Point(6, 58);
			this->label128->Name = L"label128";
			this->label128->Size = System::Drawing::Size(27, 16);
			this->label128->TabIndex = 4;
			this->label128->Text = L"XZ:";
			// 
			// numericUpDown17
			// 
			this->numericUpDown17->Location = System::Drawing::Point(40, 25);
			this->numericUpDown17->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000000, 0, 0, 0});
			this->numericUpDown17->Name = L"numericUpDown17";
			this->numericUpDown17->Size = System::Drawing::Size(120, 22);
			this->numericUpDown17->TabIndex = 9;
			// 
			// label129
			// 
			this->label129->AutoSize = true;
			this->label129->Location = System::Drawing::Point(6, 27);
			this->label129->Name = L"label129";
			this->label129->Size = System::Drawing::Size(28, 16);
			this->label129->TabIndex = 6;
			this->label129->Text = L"XY:";
			// 
			// groupBox24
			// 
			this->groupBox24->Controls->Add(this->maskedTextBox31);
			this->groupBox24->Controls->Add(this->label118);
			this->groupBox24->Controls->Add(this->label112);
			this->groupBox24->Controls->Add(this->label120);
			this->groupBox24->Controls->Add(this->maskedTextBox32);
			this->groupBox24->Controls->Add(this->numericUpDown14);
			this->groupBox24->Controls->Add(this->label113);
			this->groupBox24->Controls->Add(this->label119);
			this->groupBox24->Controls->Add(this->label114);
			this->groupBox24->Controls->Add(this->label117);
			this->groupBox24->Controls->Add(this->maskedTextBox33);
			this->groupBox24->Controls->Add(this->numericUpDown13);
			this->groupBox24->Controls->Add(this->label115);
			this->groupBox24->Controls->Add(this->label116);
			this->groupBox24->Controls->Add(this->numericUpDown12);
			this->groupBox24->Location = System::Drawing::Point(473, 21);
			this->groupBox24->Name = L"groupBox24";
			this->groupBox24->Size = System::Drawing::Size(481, 136);
			this->groupBox24->TabIndex = 6;
			this->groupBox24->TabStop = false;
			this->groupBox24->Text = L"Skin depth emulator";
			// 
			// maskedTextBox31
			// 
			this->maskedTextBox31->Location = System::Drawing::Point(274, 80);
			this->maskedTextBox31->Name = L"maskedTextBox31";
			this->maskedTextBox31->ReadOnly = true;
			this->maskedTextBox31->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox31->TabIndex = 16;
			this->maskedTextBox31->Text = L"0.0";
			// 
			// label118
			// 
			this->label118->AutoSize = true;
			this->label118->Location = System::Drawing::Point(165, 21);
			this->label118->Name = L"label118";
			this->label118->Size = System::Drawing::Size(69, 16);
			this->label118->TabIndex = 11;
			this->label118->Text = L"-arb. units-";
			// 
			// label112
			// 
			this->label112->AutoSize = true;
			this->label112->Location = System::Drawing::Point(380, 83);
			this->label112->Name = L"label112";
			this->label112->Size = System::Drawing::Size(19, 16);
			this->label112->TabIndex = 12;
			this->label112->Text = L"m";
			// 
			// label120
			// 
			this->label120->AutoSize = true;
			this->label120->Location = System::Drawing::Point(5, 21);
			this->label120->Name = L"label120";
			this->label120->Size = System::Drawing::Size(19, 16);
			this->label120->TabIndex = 6;
			this->label120->Text = L"X:";
			// 
			// maskedTextBox32
			// 
			this->maskedTextBox32->Location = System::Drawing::Point(274, 49);
			this->maskedTextBox32->Name = L"maskedTextBox32";
			this->maskedTextBox32->ReadOnly = true;
			this->maskedTextBox32->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox32->TabIndex = 18;
			this->maskedTextBox32->Text = L"0.0";
			// 
			// numericUpDown14
			// 
			this->numericUpDown14->Location = System::Drawing::Point(39, 19);
			this->numericUpDown14->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000000, 0, 0, 0});
			this->numericUpDown14->Name = L"numericUpDown14";
			this->numericUpDown14->Size = System::Drawing::Size(120, 22);
			this->numericUpDown14->TabIndex = 9;
			this->numericUpDown14->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown14_ValueChanged);
			// 
			// label113
			// 
			this->label113->AutoSize = true;
			this->label113->Location = System::Drawing::Point(380, 52);
			this->label113->Name = L"label113";
			this->label113->Size = System::Drawing::Size(19, 16);
			this->label113->TabIndex = 10;
			this->label113->Text = L"m";
			// 
			// label119
			// 
			this->label119->AutoSize = true;
			this->label119->Location = System::Drawing::Point(5, 52);
			this->label119->Name = L"label119";
			this->label119->Size = System::Drawing::Size(20, 16);
			this->label119->TabIndex = 4;
			this->label119->Text = L"Y:";
			// 
			// label114
			// 
			this->label114->AutoSize = true;
			this->label114->Location = System::Drawing::Point(165, 83);
			this->label114->Name = L"label114";
			this->label114->Size = System::Drawing::Size(69, 16);
			this->label114->TabIndex = 13;
			this->label114->Text = L"-arb. units-";
			// 
			// label117
			// 
			this->label117->AutoSize = true;
			this->label117->Location = System::Drawing::Point(5, 83);
			this->label117->Name = L"label117";
			this->label117->Size = System::Drawing::Size(19, 16);
			this->label117->TabIndex = 5;
			this->label117->Text = L"Z:";
			// 
			// maskedTextBox33
			// 
			this->maskedTextBox33->Location = System::Drawing::Point(274, 18);
			this->maskedTextBox33->Name = L"maskedTextBox33";
			this->maskedTextBox33->ReadOnly = true;
			this->maskedTextBox33->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox33->TabIndex = 17;
			this->maskedTextBox33->Text = L"0.0";
			// 
			// numericUpDown13
			// 
			this->numericUpDown13->Location = System::Drawing::Point(39, 50);
			this->numericUpDown13->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000000, 0, 0, 0});
			this->numericUpDown13->Name = L"numericUpDown13";
			this->numericUpDown13->Size = System::Drawing::Size(120, 22);
			this->numericUpDown13->TabIndex = 8;
			this->numericUpDown13->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown13_ValueChanged);
			// 
			// label115
			// 
			this->label115->AutoSize = true;
			this->label115->Location = System::Drawing::Point(165, 52);
			this->label115->Name = L"label115";
			this->label115->Size = System::Drawing::Size(69, 16);
			this->label115->TabIndex = 14;
			this->label115->Text = L"-arb. units-";
			// 
			// label116
			// 
			this->label116->AutoSize = true;
			this->label116->Location = System::Drawing::Point(380, 21);
			this->label116->Name = L"label116";
			this->label116->Size = System::Drawing::Size(19, 16);
			this->label116->TabIndex = 15;
			this->label116->Text = L"m";
			// 
			// numericUpDown12
			// 
			this->numericUpDown12->Location = System::Drawing::Point(39, 81);
			this->numericUpDown12->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000000, 0, 0, 0});
			this->numericUpDown12->Name = L"numericUpDown12";
			this->numericUpDown12->Size = System::Drawing::Size(120, 22);
			this->numericUpDown12->TabIndex = 7;
			this->numericUpDown12->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown12_ValueChanged);
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->ItemHeight = 16;
			this->listBox4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"Rectangular", L"File based"});
			this->listBox4->Location = System::Drawing::Point(107, 21);
			this->listBox4->MultiColumn = true;
			this->listBox4->Name = L"listBox4";
			this->listBox4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->listBox4->Size = System::Drawing::Size(203, 52);
			this->listBox4->TabIndex = 5;
			this->listBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox4_SelectedIndexChanged);
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->maskedTextBox25);
			this->groupBox10->Controls->Add(this->label58);
			this->groupBox10->Controls->Add(this->maskedTextBox22);
			this->groupBox10->Controls->Add(this->maskedTextBox24);
			this->groupBox10->Controls->Add(this->label49);
			this->groupBox10->Controls->Add(this->label57);
			this->groupBox10->Controls->Add(this->maskedTextBox21);
			this->groupBox10->Controls->Add(this->label56);
			this->groupBox10->Controls->Add(this->label46);
			this->groupBox10->Controls->Add(this->maskedTextBox23);
			this->groupBox10->Controls->Add(this->label48);
			this->groupBox10->Controls->Add(this->label55);
			this->groupBox10->Controls->Add(this->maskedTextBox20);
			this->groupBox10->Controls->Add(this->numericUpDown6);
			this->groupBox10->Controls->Add(this->label43);
			this->groupBox10->Controls->Add(this->label54);
			this->groupBox10->Controls->Add(this->numericUpDown3);
			this->groupBox10->Controls->Add(this->numericUpDown5);
			this->groupBox10->Controls->Add(this->label45);
			this->groupBox10->Controls->Add(this->label53);
			this->groupBox10->Controls->Add(this->numericUpDown2);
			this->groupBox10->Controls->Add(this->label52);
			this->groupBox10->Controls->Add(this->label47);
			this->groupBox10->Controls->Add(this->label51);
			this->groupBox10->Controls->Add(this->label44);
			this->groupBox10->Controls->Add(this->numericUpDown4);
			this->groupBox10->Controls->Add(this->label42);
			this->groupBox10->Controls->Add(this->label50);
			this->groupBox10->Controls->Add(this->numericUpDown1);
			this->groupBox10->Controls->Add(this->label41);
			this->groupBox10->Location = System::Drawing::Point(9, 82);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(458, 215);
			this->groupBox10->TabIndex = 2;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Rectangular probe configuration";
			// 
			// maskedTextBox25
			// 
			this->maskedTextBox25->Location = System::Drawing::Point(275, 175);
			this->maskedTextBox25->Name = L"maskedTextBox25";
			this->maskedTextBox25->ReadOnly = true;
			this->maskedTextBox25->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox25->TabIndex = 3;
			this->maskedTextBox25->Text = L"0.0";
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(381, 178);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(19, 16);
			this->label58->TabIndex = 2;
			this->label58->Text = L"m";
			// 
			// maskedTextBox22
			// 
			this->maskedTextBox22->Location = System::Drawing::Point(275, 81);
			this->maskedTextBox22->Name = L"maskedTextBox22";
			this->maskedTextBox22->ReadOnly = true;
			this->maskedTextBox22->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox22->TabIndex = 3;
			this->maskedTextBox22->Text = L"0.0";
			// 
			// maskedTextBox24
			// 
			this->maskedTextBox24->Location = System::Drawing::Point(275, 144);
			this->maskedTextBox24->Name = L"maskedTextBox24";
			this->maskedTextBox24->ReadOnly = true;
			this->maskedTextBox24->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox24->TabIndex = 3;
			this->maskedTextBox24->Text = L"0.0";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(381, 84);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(19, 16);
			this->label49->TabIndex = 2;
			this->label49->Text = L"m";
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(381, 147);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(19, 16);
			this->label57->TabIndex = 2;
			this->label57->Text = L"m";
			// 
			// maskedTextBox21
			// 
			this->maskedTextBox21->Location = System::Drawing::Point(275, 50);
			this->maskedTextBox21->Name = L"maskedTextBox21";
			this->maskedTextBox21->ReadOnly = true;
			this->maskedTextBox21->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox21->TabIndex = 3;
			this->maskedTextBox21->Text = L"0.0";
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(166, 177);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(69, 16);
			this->label56->TabIndex = 2;
			this->label56->Text = L"-arb. units-";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(381, 53);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(19, 16);
			this->label46->TabIndex = 2;
			this->label46->Text = L"m";
			// 
			// maskedTextBox23
			// 
			this->maskedTextBox23->Location = System::Drawing::Point(275, 113);
			this->maskedTextBox23->Name = L"maskedTextBox23";
			this->maskedTextBox23->ReadOnly = true;
			this->maskedTextBox23->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox23->TabIndex = 3;
			this->maskedTextBox23->Text = L"0.0";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(166, 83);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(69, 16);
			this->label48->TabIndex = 2;
			this->label48->Text = L"-arb. units-";
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(166, 146);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(69, 16);
			this->label55->TabIndex = 2;
			this->label55->Text = L"-arb. units-";
			// 
			// maskedTextBox20
			// 
			this->maskedTextBox20->Location = System::Drawing::Point(275, 19);
			this->maskedTextBox20->Name = L"maskedTextBox20";
			this->maskedTextBox20->ReadOnly = true;
			this->maskedTextBox20->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox20->TabIndex = 3;
			this->maskedTextBox20->Text = L"0.0";
			// 
			// numericUpDown6
			// 
			this->numericUpDown6->Location = System::Drawing::Point(40, 175);
			this->numericUpDown6->Name = L"numericUpDown6";
			this->numericUpDown6->Size = System::Drawing::Size(120, 22);
			this->numericUpDown6->TabIndex = 1;
			this->numericUpDown6->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown6_ValueChanged);
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(166, 52);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(69, 16);
			this->label43->TabIndex = 2;
			this->label43->Text = L"-arb. units-";
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(381, 116);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(19, 16);
			this->label54->TabIndex = 2;
			this->label54->Text = L"m";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(40, 81);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 22);
			this->numericUpDown3->TabIndex = 1;
			this->numericUpDown3->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown3_ValueChanged);
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(40, 144);
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(120, 22);
			this->numericUpDown5->TabIndex = 1;
			this->numericUpDown5->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown5_ValueChanged);
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(381, 22);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(19, 16);
			this->label45->TabIndex = 2;
			this->label45->Text = L"m";
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(6, 177);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(26, 16);
			this->label53->TabIndex = 0;
			this->label53->Text = L"Z1:";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(40, 50);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 22);
			this->numericUpDown2->TabIndex = 1;
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown2_ValueChanged);
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(166, 115);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(69, 16);
			this->label52->TabIndex = 2;
			this->label52->Text = L"-arb. units-";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(6, 83);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(26, 16);
			this->label47->TabIndex = 0;
			this->label47->Text = L"Z0:";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(6, 146);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(27, 16);
			this->label51->TabIndex = 0;
			this->label51->Text = L"Y1:";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(166, 21);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(69, 16);
			this->label44->TabIndex = 2;
			this->label44->Text = L"-arb. units-";
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(40, 113);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(120, 22);
			this->numericUpDown4->TabIndex = 1;
			this->numericUpDown4->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown4_ValueChanged);
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(6, 52);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(27, 16);
			this->label42->TabIndex = 0;
			this->label42->Text = L"Y0:";
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(6, 115);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(26, 16);
			this->label50->TabIndex = 0;
			this->label50->Text = L"X1:";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(40, 19);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 1;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown1_ValueChanged);
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(6, 21);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(26, 16);
			this->label41->TabIndex = 0;
			this->label41->Text = L"X0:";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(6, 21);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(77, 16);
			this->label40->TabIndex = 0;
			this->label40->Text = L"Probe type:";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->radioButton9);
			this->groupBox8->Controls->Add(this->radioButton6);
			this->groupBox8->Controls->Add(this->radioButton5);
			this->groupBox8->Location = System::Drawing::Point(6, 162);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(159, 130);
			this->groupBox8->TabIndex = 2;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Viewport";
			// 
			// radioButton9
			// 
			this->radioButton9->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton9->AutoSize = true;
			this->radioButton9->FlatAppearance->CheckedBackColor = System::Drawing::Color::DodgerBlue;
			this->radioButton9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton9->Location = System::Drawing::Point(41, 92);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(74, 28);
			this->radioButton9->TabIndex = 0;
			this->radioButton9->Text = L"YZ plane";
			this->radioButton9->UseVisualStyleBackColor = true;
			this->radioButton9->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton9_CheckedChanged);
			// 
			// radioButton6
			// 
			this->radioButton6->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton6->AutoSize = true;
			this->radioButton6->FlatAppearance->CheckedBackColor = System::Drawing::Color::DodgerBlue;
			this->radioButton6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton6->Location = System::Drawing::Point(41, 59);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(73, 28);
			this->radioButton6->TabIndex = 0;
			this->radioButton6->Text = L"XZ plane";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton6_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton5->AutoSize = true;
			this->radioButton5->Checked = true;
			this->radioButton5->FlatAppearance->CheckedBackColor = System::Drawing::Color::DodgerBlue;
			this->radioButton5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->radioButton5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton5->Location = System::Drawing::Point(41, 26);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(74, 28);
			this->radioButton5->TabIndex = 0;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"XY plane";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton5_CheckedChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::Color::DimGray;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(6, 315);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1212, 261);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(6, 295);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(63, 16);
			this->label39->TabIndex = 0;
			this->label39->Text = L"Viewport:";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label130);
			this->tabPage3->Controls->Add(this->listBox22);
			this->tabPage3->Controls->Add(this->label106);
			this->tabPage3->Controls->Add(this->label107);
			this->tabPage3->Controls->Add(this->trackBar3);
			this->tabPage3->Controls->Add(this->label104);
			this->tabPage3->Controls->Add(this->label105);
			this->tabPage3->Controls->Add(this->trackBar2);
			this->tabPage3->Controls->Add(this->label67);
			this->tabPage3->Controls->Add(this->label66);
			this->tabPage3->Controls->Add(this->label65);
			this->tabPage3->Controls->Add(this->label64);
			this->tabPage3->Controls->Add(this->label62);
			this->tabPage3->Controls->Add(this->label61);
			this->tabPage3->Controls->Add(this->label60);
			this->tabPage3->Controls->Add(this->label59);
			this->tabPage3->Controls->Add(this->panel2);
			this->tabPage3->Controls->Add(this->panel1);
			this->tabPage3->Controls->Add(this->groupBox11);
			this->tabPage3->Controls->Add(this->button9);
			this->tabPage3->Controls->Add(this->button6);
			this->tabPage3->Controls->Add(this->button7);
			this->tabPage3->Controls->Add(this->button5);
			this->tabPage3->Controls->Add(this->button8);
			this->tabPage3->Location = System::Drawing::Point(4, 68);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1224, 568);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Time domain and propagation analysies";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label130
			// 
			this->label130->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label130->AutoSize = true;
			this->label130->Location = System::Drawing::Point(630, 166);
			this->label130->Name = L"label130";
			this->label130->Size = System::Drawing::Size(79, 16);
			this->label130->TabIndex = 42;
			this->label130->Text = L"Color scale:";
			this->label130->Click += gcnew System::EventHandler(this, &Form1::label130_Click);
			// 
			// listBox22
			// 
			this->listBox22->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->listBox22->FormattingEnabled = true;
			this->listBox22->ItemHeight = 16;
			this->listBox22->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"LINEAR", L"LOG10", L"SQRT", L"2SQRT", L"LOG100", 
				L"X^2"});
			this->listBox22->Location = System::Drawing::Point(633, 185);
			this->listBox22->MultiColumn = true;
			this->listBox22->Name = L"listBox22";
			this->listBox22->Size = System::Drawing::Size(475, 36);
			this->listBox22->TabIndex = 41;
			this->listBox22->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox22_SelectedIndexChanged);
			// 
			// label106
			// 
			this->label106->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label106->AutoSize = true;
			this->label106->Location = System::Drawing::Point(903, 153);
			this->label106->Name = L"label106";
			this->label106->Size = System::Drawing::Size(74, 16);
			this->label106->TabIndex = 40;
			this->label106->Text = L"Brightness:";
			// 
			// label107
			// 
			this->label107->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label107->AutoSize = true;
			this->label107->Location = System::Drawing::Point(1049, 166);
			this->label107->Name = L"label107";
			this->label107->Size = System::Drawing::Size(15, 16);
			this->label107->TabIndex = 39;
			this->label107->Text = L"1";
			this->label107->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar3
			// 
			this->trackBar3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->trackBar3->LargeChange = 100;
			this->trackBar3->Location = System::Drawing::Point(1004, 137);
			this->trackBar3->Maximum = 100000;
			this->trackBar3->Minimum = 1;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(104, 45);
			this->trackBar3->TabIndex = 38;
			this->trackBar3->TickFrequency = 10000;
			this->trackBar3->Value = 1;
			this->trackBar3->ValueChanged += gcnew System::EventHandler(this, &Form1::trackBar3_ValueChanged);
			// 
			// label104
			// 
			this->label104->AutoSize = true;
			this->label104->Location = System::Drawing::Point(34, 205);
			this->label104->Name = L"label104";
			this->label104->Size = System::Drawing::Size(74, 16);
			this->label104->TabIndex = 37;
			this->label104->Text = L"Brightness:";
			// 
			// label105
			// 
			this->label105->AutoSize = true;
			this->label105->Location = System::Drawing::Point(180, 217);
			this->label105->Name = L"label105";
			this->label105->Size = System::Drawing::Size(15, 16);
			this->label105->TabIndex = 36;
			this->label105->Text = L"1";
			this->label105->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar2
			// 
			this->trackBar2->LargeChange = 100;
			this->trackBar2->Location = System::Drawing::Point(135, 189);
			this->trackBar2->Maximum = 1000;
			this->trackBar2->Minimum = 1;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(104, 45);
			this->trackBar2->TabIndex = 35;
			this->trackBar2->TickFrequency = 100;
			this->trackBar2->Value = 1;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &Form1::trackBar2_Scroll);
			// 
			// label67
			// 
			this->label67->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label67->AutoSize = true;
			this->label67->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label67->Location = System::Drawing::Point(1074, 237);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(27, 17);
			this->label67->TabIndex = 5;
			this->label67->Text = L"XF";
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label66->Location = System::Drawing::Point(347, 235);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(28, 17);
			this->label66->TabIndex = 5;
			this->label66->Text = L"XT";
			// 
			// label65
			// 
			this->label65->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label65->AutoSize = true;
			this->label65->Location = System::Drawing::Point(717, 237);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(273, 16);
			this->label65->TabIndex = 4;
			this->label65->Text = L"Amplitude against frequency and coordinate:";
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Location = System::Drawing::Point(30, 237);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(239, 16);
			this->label64->TabIndex = 4;
			this->label64->Text = L"Amplitude against time and coordinate:";
			// 
			// label62
			// 
			this->label62->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(951, 565);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(74, 16);
			this->label62->TabIndex = 1;
			this->label62->Text = L"Coordinate";
			this->label62->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// label61
			// 
			this->label61->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(196, 565);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(74, 16);
			this->label61->TabIndex = 1;
			this->label61->Text = L"Coordinate";
			this->label61->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// label60
			// 
			this->label60->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(632, 431);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(16, 16);
			this->label60->TabIndex = 1;
			this->label60->Text = L"F";
			this->label60->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(9, 431);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(17, 16);
			this->label59->TabIndex = 1;
			this->label59->Text = L"T";
			this->label59->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel2->Controls->Add(this->pictureBox3);
			this->panel2->Location = System::Drawing::Point(717, 257);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(504, 300);
			this->panel2->TabIndex = 3;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox3->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Location = System::Drawing::Point(3, 3);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(498, 294);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 0;
			this->pictureBox3->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Location = System::Drawing::Point(30, 257);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(504, 300);
			this->panel1->TabIndex = 3;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(3, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(498, 294);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->listBox5);
			this->groupBox11->Location = System::Drawing::Point(3, 3);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(154, 96);
			this->groupBox11->TabIndex = 1;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Projection type:";
			// 
			// listBox5
			// 
			this->listBox5->FormattingEnabled = true;
			this->listBox5->ItemHeight = 16;
			this->listBox5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"XT-XF", L"YT-YF", L"ZT-ZF"});
			this->listBox5->Location = System::Drawing::Point(50, 21);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(55, 52);
			this->listBox5->TabIndex = 0;
			this->listBox5->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox5_SelectedIndexChanged);
			// 
			// button9
			// 
			this->button9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button9->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button9->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Location = System::Drawing::Point(1114, 192);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(104, 28);
			this->button9->TabIndex = 0;
			this->button9->Text = L"Export TXT";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Location = System::Drawing::Point(430, 183);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(104, 28);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Export TXT";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Location = System::Drawing::Point(1114, 226);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(104, 28);
			this->button7->TabIndex = 0;
			this->button7->Text = L"Export IMG";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(430, 217);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(104, 28);
			this->button5->TabIndex = 0;
			this->button5->Text = L"Export IMG";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Lime;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Location = System::Drawing::Point(163, 14);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(153, 85);
			this->button8->TabIndex = 0;
			this->button8->Text = L"GENERATE";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// tabPage8
			// 
			this->tabPage8->Controls->Add(this->groupBox28);
			this->tabPage8->Controls->Add(this->groupBox26);
			this->tabPage8->Controls->Add(this->label111);
			this->tabPage8->Controls->Add(this->label110);
			this->tabPage8->Controls->Add(this->button15);
			this->tabPage8->Controls->Add(this->button14);
			this->tabPage8->Controls->Add(this->groupBox14);
			this->tabPage8->Controls->Add(this->groupBox13);
			this->tabPage8->Controls->Add(this->groupBox15);
			this->tabPage8->Controls->Add(this->groupBox12);
			this->tabPage8->Controls->Add(this->label68);
			this->tabPage8->Controls->Add(this->label69);
			this->tabPage8->Controls->Add(this->label70);
			this->tabPage8->Controls->Add(this->label71);
			this->tabPage8->Controls->Add(this->label72);
			this->tabPage8->Controls->Add(this->label73);
			this->tabPage8->Controls->Add(this->label74);
			this->tabPage8->Controls->Add(this->label75);
			this->tabPage8->Controls->Add(this->panel3);
			this->tabPage8->Controls->Add(this->panel4);
			this->tabPage8->Controls->Add(this->button10);
			this->tabPage8->Controls->Add(this->button11);
			this->tabPage8->Controls->Add(this->button12);
			this->tabPage8->Controls->Add(this->button13);
			this->tabPage8->Location = System::Drawing::Point(4, 68);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Padding = System::Windows::Forms::Padding(3);
			this->tabPage8->Size = System::Drawing::Size(1224, 568);
			this->tabPage8->TabIndex = 8;
			this->tabPage8->Text = L"mmDisplay";
			this->tabPage8->UseVisualStyleBackColor = true;
			this->tabPage8->Enter += gcnew System::EventHandler(this, &Form1::tabPage8_Enter);
			// 
			// groupBox28
			// 
			this->groupBox28->Controls->Add(this->richTextBox3);
			this->groupBox28->Location = System::Drawing::Point(793, 108);
			this->groupBox28->Name = L"groupBox28";
			this->groupBox28->Size = System::Drawing::Size(223, 125);
			this->groupBox28->TabIndex = 26;
			this->groupBox28->TabStop = false;
			this->groupBox28->Text = L"Mode details";
			// 
			// richTextBox3
			// 
			this->richTextBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox3->Location = System::Drawing::Point(8, 21);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(207, 96);
			this->richTextBox3->TabIndex = 0;
			this->richTextBox3->Text = L"";
			// 
			// groupBox26
			// 
			this->groupBox26->Controls->Add(this->richTextBox2);
			this->groupBox26->Location = System::Drawing::Point(564, 108);
			this->groupBox26->Name = L"groupBox26";
			this->groupBox26->Size = System::Drawing::Size(223, 125);
			this->groupBox26->TabIndex = 25;
			this->groupBox26->TabStop = false;
			this->groupBox26->Text = L"Multipole expansion";
			// 
			// richTextBox2
			// 
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox2->Location = System::Drawing::Point(8, 21);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(207, 96);
			this->richTextBox2->TabIndex = 0;
			this->richTextBox2->Text = L"";
			// 
			// label111
			// 
			this->label111->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label111->AutoSize = true;
			this->label111->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label111->Location = System::Drawing::Point(702, 236);
			this->label111->Name = L"label111";
			this->label111->Size = System::Drawing::Size(77, 17);
			this->label111->TabIndex = 24;
			this->label111->Text = L"Img/Phase";
			// 
			// label110
			// 
			this->label110->AutoSize = true;
			this->label110->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label110->Location = System::Drawing::Point(93, 234);
			this->label110->Name = L"label110";
			this->label110->Size = System::Drawing::Size(62, 17);
			this->label110->TabIndex = 23;
			this->label110->Text = L"Re/Amp";
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Location = System::Drawing::Point(986, 16);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(70, 86);
			this->button15->TabIndex = 22;
			this->button15->Text = L"SAVE";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button14->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Lime;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Location = System::Drawing::Point(755, 16);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(70, 86);
			this->button14->TabIndex = 21;
			this->button14->Text = L"VIEW";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// groupBox14
			// 
			this->groupBox14->Controls->Add(this->maskedTextBox27);
			this->groupBox14->Controls->Add(this->label82);
			this->groupBox14->Controls->Add(this->label83);
			this->groupBox14->Controls->Add(this->numericUpDown8);
			this->groupBox14->Controls->Add(this->label80);
			this->groupBox14->Controls->Add(this->label81);
			this->groupBox14->Controls->Add(this->maskedTextBox26);
			this->groupBox14->Controls->Add(this->numericUpDown7);
			this->groupBox14->Controls->Add(this->label79);
			this->groupBox14->Controls->Add(this->label77);
			this->groupBox14->Controls->Add(this->label78);
			this->groupBox14->Controls->Add(this->label76);
			this->groupBox14->Location = System::Drawing::Point(171, 6);
			this->groupBox14->Name = L"groupBox14";
			this->groupBox14->Size = System::Drawing::Size(387, 148);
			this->groupBox14->TabIndex = 2;
			this->groupBox14->TabStop = false;
			this->groupBox14->Text = L"Probe";
			// 
			// maskedTextBox27
			// 
			this->maskedTextBox27->Location = System::Drawing::Point(155, 112);
			this->maskedTextBox27->Name = L"maskedTextBox27";
			this->maskedTextBox27->ReadOnly = true;
			this->maskedTextBox27->Size = System::Drawing::Size(131, 22);
			this->maskedTextBox27->TabIndex = 8;
			this->maskedTextBox27->Text = L"0.0";
			// 
			// label82
			// 
			this->label82->AutoSize = true;
			this->label82->Location = System::Drawing::Point(292, 112);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(19, 16);
			this->label82->TabIndex = 7;
			this->label82->Text = L"m";
			// 
			// label83
			// 
			this->label83->AutoSize = true;
			this->label83->Location = System::Drawing::Point(6, 115);
			this->label83->Name = L"label83";
			this->label83->Size = System::Drawing::Size(19, 16);
			this->label83->TabIndex = 6;
			this->label83->Text = L"Z:";
			// 
			// numericUpDown8
			// 
			this->numericUpDown8->Location = System::Drawing::Point(155, 81);
			this->numericUpDown8->Name = L"numericUpDown8";
			this->numericUpDown8->Size = System::Drawing::Size(131, 22);
			this->numericUpDown8->TabIndex = 5;
			this->numericUpDown8->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown8_ValueChanged);
			// 
			// label80
			// 
			this->label80->AutoSize = true;
			this->label80->Location = System::Drawing::Point(292, 83);
			this->label80->Name = L"label80";
			this->label80->Size = System::Drawing::Size(61, 16);
			this->label80->TabIndex = 4;
			this->label80->Text = L"arb. units";
			// 
			// label81
			// 
			this->label81->AutoSize = true;
			this->label81->Location = System::Drawing::Point(6, 83);
			this->label81->Name = L"label81";
			this->label81->Size = System::Drawing::Size(19, 16);
			this->label81->TabIndex = 3;
			this->label81->Text = L"Z:";
			// 
			// maskedTextBox26
			// 
			this->maskedTextBox26->Location = System::Drawing::Point(155, 50);
			this->maskedTextBox26->Name = L"maskedTextBox26";
			this->maskedTextBox26->ReadOnly = true;
			this->maskedTextBox26->Size = System::Drawing::Size(131, 22);
			this->maskedTextBox26->TabIndex = 2;
			this->maskedTextBox26->Text = L"0.0";
			// 
			// numericUpDown7
			// 
			this->numericUpDown7->Location = System::Drawing::Point(155, 19);
			this->numericUpDown7->Name = L"numericUpDown7";
			this->numericUpDown7->Size = System::Drawing::Size(131, 22);
			this->numericUpDown7->TabIndex = 1;
			this->numericUpDown7->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown7_ValueChanged);
			// 
			// label79
			// 
			this->label79->AutoSize = true;
			this->label79->Location = System::Drawing::Point(292, 50);
			this->label79->Name = L"label79";
			this->label79->Size = System::Drawing::Size(15, 16);
			this->label79->TabIndex = 0;
			this->label79->Text = L"s";
			// 
			// label77
			// 
			this->label77->AutoSize = true;
			this->label77->Location = System::Drawing::Point(292, 21);
			this->label77->Name = L"label77";
			this->label77->Size = System::Drawing::Size(61, 16);
			this->label77->TabIndex = 0;
			this->label77->Text = L"arb. units";
			// 
			// label78
			// 
			this->label78->AutoSize = true;
			this->label78->Location = System::Drawing::Point(6, 53);
			this->label78->Name = L"label78";
			this->label78->Size = System::Drawing::Size(71, 16);
			this->label78->TabIndex = 0;
			this->label78->Text = L"Time step:";
			// 
			// label76
			// 
			this->label76->AutoSize = true;
			this->label76->Location = System::Drawing::Point(6, 21);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(71, 16);
			this->label76->TabIndex = 0;
			this->label76->Text = L"Time step:";
			// 
			// groupBox13
			// 
			this->groupBox13->Controls->Add(this->listBox8);
			this->groupBox13->Location = System::Drawing::Point(564, 6);
			this->groupBox13->Name = L"groupBox13";
			this->groupBox13->Size = System::Drawing::Size(185, 96);
			this->groupBox13->TabIndex = 2;
			this->groupBox13->TabStop = false;
			this->groupBox13->Text = L"Mode:";
			// 
			// listBox8
			// 
			this->listBox8->FormattingEnabled = true;
			this->listBox8->ItemHeight = 16;
			this->listBox8->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Real and imaginary", L"Amplitude and phase"});
			this->listBox8->Location = System::Drawing::Point(6, 24);
			this->listBox8->Name = L"listBox8";
			this->listBox8->Size = System::Drawing::Size(173, 36);
			this->listBox8->TabIndex = 0;
			this->listBox8->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox8_SelectedIndexChanged);
			// 
			// groupBox15
			// 
			this->groupBox15->Controls->Add(this->listBox9);
			this->groupBox15->Location = System::Drawing::Point(831, 6);
			this->groupBox15->Name = L"groupBox15";
			this->groupBox15->Size = System::Drawing::Size(149, 96);
			this->groupBox15->TabIndex = 20;
			this->groupBox15->TabStop = false;
			this->groupBox15->Text = L"Batch save mode";
			// 
			// listBox9
			// 
			this->listBox9->Enabled = false;
			this->listBox9->FormattingEnabled = true;
			this->listBox9->ItemHeight = 16;
			this->listBox9->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Image", L"Text"});
			this->listBox9->Location = System::Drawing::Point(16, 24);
			this->listBox9->Name = L"listBox9";
			this->listBox9->Size = System::Drawing::Size(113, 36);
			this->listBox9->TabIndex = 0;
			this->listBox9->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox9_SelectedIndexChanged);
			// 
			// groupBox12
			// 
			this->groupBox12->Controls->Add(this->listBox7);
			this->groupBox12->Location = System::Drawing::Point(10, 6);
			this->groupBox12->Name = L"groupBox12";
			this->groupBox12->Size = System::Drawing::Size(155, 96);
			this->groupBox12->TabIndex = 20;
			this->groupBox12->TabStop = false;
			this->groupBox12->Text = L"Projection type:";
			// 
			// listBox7
			// 
			this->listBox7->FormattingEnabled = true;
			this->listBox7->ItemHeight = 16;
			this->listBox7->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"XY", L"XZ", L"YZ"});
			this->listBox7->Location = System::Drawing::Point(49, 24);
			this->listBox7->Name = L"listBox7";
			this->listBox7->Size = System::Drawing::Size(51, 52);
			this->listBox7->TabIndex = 0;
			this->listBox7->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox7_SelectedIndexChanged);
			// 
			// label68
			// 
			this->label68->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label68->AutoSize = true;
			this->label68->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label68->Location = System::Drawing::Point(1078, 234);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(28, 17);
			this->label68->TabIndex = 18;
			this->label68->Text = L"XY";
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label69->Location = System::Drawing::Point(406, 233);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(28, 17);
			this->label69->TabIndex = 19;
			this->label69->Text = L"XY";
			// 
			// label70
			// 
			this->label70->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label70->AutoSize = true;
			this->label70->Location = System::Drawing::Point(833, 236);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(187, 16);
			this->label70->TabIndex = 16;
			this->label70->Text = L"Value against 2D coordinates:";
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Location = System::Drawing::Point(161, 236);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(187, 16);
			this->label71->TabIndex = 17;
			this->label71->Text = L"Value against 2D coordinates:";
			// 
			// label72
			// 
			this->label72->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label72->AutoSize = true;
			this->label72->Location = System::Drawing::Point(917, 542);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(16, 16);
			this->label72->TabIndex = 12;
			this->label72->Text = L"X";
			this->label72->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// label73
			// 
			this->label73->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label73->AutoSize = true;
			this->label73->Location = System::Drawing::Point(241, 542);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(16, 16);
			this->label73->TabIndex = 13;
			this->label73->Text = L"X";
			this->label73->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// label74
			// 
			this->label74->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label74->AutoSize = true;
			this->label74->Location = System::Drawing::Point(655, 428);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(17, 16);
			this->label74->TabIndex = 10;
			this->label74->Text = L"Y";
			this->label74->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// label75
			// 
			this->label75->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label75->AutoSize = true;
			this->label75->Location = System::Drawing::Point(7, 428);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(17, 16);
			this->label75->TabIndex = 11;
			this->label75->Text = L"Y";
			this->label75->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel3->Controls->Add(this->pictureBox6);
			this->panel3->Location = System::Drawing::Point(702, 256);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(514, 283);
			this->panel3->TabIndex = 15;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox6->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox6->Location = System::Drawing::Point(3, 3);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(508, 263);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 0;
			this->pictureBox6->TabStop = false;
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel4->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel4->Controls->Add(this->pictureBox7);
			this->panel4->Location = System::Drawing::Point(30, 256);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(514, 283);
			this->panel4->TabIndex = 14;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox7->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox7->Location = System::Drawing::Point(3, 3);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(508, 263);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 0;
			this->pictureBox7->TabStop = false;
			// 
			// button10
			// 
			this->button10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button10->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Location = System::Drawing::Point(1112, 188);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(104, 28);
			this->button10->TabIndex = 7;
			this->button10->Text = L"Export TXT";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Location = System::Drawing::Point(440, 188);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(104, 28);
			this->button11->TabIndex = 6;
			this->button11->Text = L"Export TXT";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button12
			// 
			this->button12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Location = System::Drawing::Point(1112, 222);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(104, 28);
			this->button12->TabIndex = 9;
			this->button12->Text = L"Export IMG";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Location = System::Drawing::Point(440, 222);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(104, 28);
			this->button13->TabIndex = 8;
			this->button13->Text = L"Export IMG";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->groupBox27);
			this->tabPage4->Controls->Add(this->groupBox18);
			this->tabPage4->Controls->Add(this->button17);
			this->tabPage4->Controls->Add(this->groupBox17);
			this->tabPage4->Controls->Add(this->label85);
			this->tabPage4->Controls->Add(this->label86);
			this->tabPage4->Controls->Add(this->label87);
			this->tabPage4->Controls->Add(this->panel5);
			this->tabPage4->Controls->Add(this->button16);
			this->tabPage4->Controls->Add(this->groupBox16);
			this->tabPage4->Location = System::Drawing::Point(4, 68);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(1224, 568);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Frequnency domain analysies";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// groupBox27
			// 
			this->groupBox27->Controls->Add(this->label133);
			this->groupBox27->Controls->Add(this->label132);
			this->groupBox27->Controls->Add(this->label131);
			this->groupBox27->Controls->Add(this->listBox25);
			this->groupBox27->Controls->Add(this->listBox24);
			this->groupBox27->Controls->Add(this->listBox23);
			this->groupBox27->Location = System::Drawing::Point(6, 145);
			this->groupBox27->Name = L"groupBox27";
			this->groupBox27->Size = System::Drawing::Size(144, 91);
			this->groupBox27->TabIndex = 28;
			this->groupBox27->TabStop = false;
			this->groupBox27->Text = L"DFT configuration";
			// 
			// label133
			// 
			this->label133->AutoSize = true;
			this->label133->Location = System::Drawing::Point(104, 22);
			this->label133->Name = L"label133";
			this->label133->Size = System::Drawing::Size(16, 16);
			this->label133->TabIndex = 33;
			this->label133->Text = L"Z";
			// 
			// label132
			// 
			this->label132->AutoSize = true;
			this->label132->Location = System::Drawing::Point(61, 22);
			this->label132->Name = L"label132";
			this->label132->Size = System::Drawing::Size(17, 16);
			this->label132->TabIndex = 32;
			this->label132->Text = L"Y";
			// 
			// label131
			// 
			this->label131->AutoSize = true;
			this->label131->Location = System::Drawing::Point(20, 23);
			this->label131->Name = L"label131";
			this->label131->Size = System::Drawing::Size(16, 16);
			this->label131->TabIndex = 29;
			this->label131->Text = L"X";
			// 
			// listBox25
			// 
			this->listBox25->FormattingEnabled = true;
			this->listBox25->ItemHeight = 16;
			this->listBox25->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"NO", L"YES"});
			this->listBox25->Location = System::Drawing::Point(94, 41);
			this->listBox25->Name = L"listBox25";
			this->listBox25->Size = System::Drawing::Size(36, 36);
			this->listBox25->TabIndex = 31;
			// 
			// listBox24
			// 
			this->listBox24->FormattingEnabled = true;
			this->listBox24->ItemHeight = 16;
			this->listBox24->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"NO", L"YES"});
			this->listBox24->Location = System::Drawing::Point(52, 41);
			this->listBox24->Name = L"listBox24";
			this->listBox24->Size = System::Drawing::Size(36, 36);
			this->listBox24->TabIndex = 30;
			// 
			// listBox23
			// 
			this->listBox23->FormattingEnabled = true;
			this->listBox23->ItemHeight = 16;
			this->listBox23->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"NO", L"YES"});
			this->listBox23->Location = System::Drawing::Point(10, 41);
			this->listBox23->Name = L"listBox23";
			this->listBox23->Size = System::Drawing::Size(36, 36);
			this->listBox23->TabIndex = 29;
			// 
			// groupBox18
			// 
			this->groupBox18->Controls->Add(this->listBox13);
			this->groupBox18->Location = System::Drawing::Point(423, 6);
			this->groupBox18->Name = L"groupBox18";
			this->groupBox18->Size = System::Drawing::Size(198, 96);
			this->groupBox18->TabIndex = 3;
			this->groupBox18->TabStop = false;
			this->groupBox18->Text = L"Averaging Method:";
			// 
			// listBox13
			// 
			this->listBox13->FormattingEnabled = true;
			this->listBox13->ItemHeight = 16;
			this->listBox13->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"COMPLEX", L"COMPLEX Amplitude only"});
			this->listBox13->Location = System::Drawing::Point(6, 24);
			this->listBox13->Name = L"listBox13";
			this->listBox13->Size = System::Drawing::Size(186, 36);
			this->listBox13->TabIndex = 0;
			this->listBox13->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox13_SelectedIndexChanged);
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button17->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Location = System::Drawing::Point(934, 16);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(118, 86);
			this->button17->TabIndex = 27;
			this->button17->Text = L"SAVE";
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &Form1::button17_Click);
			// 
			// groupBox17
			// 
			this->groupBox17->Controls->Add(this->listBox12);
			this->groupBox17->Location = System::Drawing::Point(751, 6);
			this->groupBox17->Name = L"groupBox17";
			this->groupBox17->Size = System::Drawing::Size(177, 96);
			this->groupBox17->TabIndex = 3;
			this->groupBox17->TabStop = false;
			this->groupBox17->Text = L"Mode:";
			// 
			// listBox12
			// 
			this->listBox12->FormattingEnabled = true;
			this->listBox12->ItemHeight = 16;
			this->listBox12->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Re and Image", L"Amplitude and Phase"});
			this->listBox12->Location = System::Drawing::Point(6, 24);
			this->listBox12->Name = L"listBox12";
			this->listBox12->Size = System::Drawing::Size(162, 36);
			this->listBox12->TabIndex = 0;
			this->listBox12->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox12_SelectedIndexChanged);
			// 
			// label85
			// 
			this->label85->AutoSize = true;
			this->label85->Location = System::Drawing::Point(46, 239);
			this->label85->Name = L"label85";
			this->label85->Size = System::Drawing::Size(130, 16);
			this->label85->TabIndex = 26;
			this->label85->Text = L"Calculated spectrum";
			this->label85->Visible = false;
			// 
			// label86
			// 
			this->label86->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label86->AutoSize = true;
			this->label86->Location = System::Drawing::Point(479, 659);
			this->label86->Name = L"label86";
			this->label86->Size = System::Drawing::Size(72, 16);
			this->label86->TabIndex = 24;
			this->label86->Text = L"Frequency";
			this->label86->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// label87
			// 
			this->label87->AutoSize = true;
			this->label87->Location = System::Drawing::Point(3, 457);
			this->label87->Name = L"label87";
			this->label87->Size = System::Drawing::Size(36, 16);
			this->label87->TabIndex = 23;
			this->label87->Text = L"Amp";
			this->label87->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->label87->Visible = false;
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel5->Controls->Add(this->pictureBox8);
			this->panel5->Location = System::Drawing::Point(46, 259);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(860, 400);
			this->panel5->TabIndex = 25;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox8->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox8->Location = System::Drawing::Point(3, 3);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(854, 394);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox8->TabIndex = 0;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->Visible = false;
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button16->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Lime;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Location = System::Drawing::Point(627, 16);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(118, 86);
			this->button16->TabIndex = 22;
			this->button16->Text = L"CALCULATE";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
			// 
			// groupBox16
			// 
			this->groupBox16->Controls->Add(this->listBox11);
			this->groupBox16->Location = System::Drawing::Point(6, 6);
			this->groupBox16->Name = L"groupBox16";
			this->groupBox16->Size = System::Drawing::Size(411, 133);
			this->groupBox16->TabIndex = 2;
			this->groupBox16->TabStop = false;
			this->groupBox16->Text = L"Method:";
			// 
			// listBox11
			// 
			this->listBox11->FormattingEnabled = true;
			this->listBox11->ItemHeight = 16;
			this->listBox11->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Temporal FFT -> Averaging (100% spatial BW)", 
				L"Averaging -> Temporal FFT (excludes AS modes)", L"Full DFT -> Averaging (50% spatial BW)", L"Custom DFT -> Averaging"});
			this->listBox11->Location = System::Drawing::Point(6, 24);
			this->listBox11->Name = L"listBox11";
			this->listBox11->Size = System::Drawing::Size(399, 84);
			this->listBox11->TabIndex = 0;
			this->listBox11->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox11_SelectedIndexChanged);
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->label109);
			this->tabPage5->Controls->Add(this->listBox21);
			this->tabPage5->Controls->Add(this->label108);
			this->tabPage5->Controls->Add(this->label103);
			this->tabPage5->Controls->Add(this->label1);
			this->tabPage5->Controls->Add(this->trackBar1);
			this->tabPage5->Controls->Add(this->button22);
			this->tabPage5->Controls->Add(this->label102);
			this->tabPage5->Controls->Add(this->pictureBox9);
			this->tabPage5->Controls->Add(this->groupBox19);
			this->tabPage5->Controls->Add(this->button18);
			this->tabPage5->Location = System::Drawing::Point(4, 68);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(1224, 568);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Dispersion analysies";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// label109
			// 
			this->label109->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label109->AutoSize = true;
			this->label109->Location = System::Drawing::Point(282, 405);
			this->label109->Name = L"label109";
			this->label109->Size = System::Drawing::Size(79, 16);
			this->label109->TabIndex = 36;
			this->label109->Text = L"Color scale:";
			// 
			// listBox21
			// 
			this->listBox21->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->listBox21->FormattingEnabled = true;
			this->listBox21->ItemHeight = 16;
			this->listBox21->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"LINEAR", L"LOG10", L"SQRT", L"2SQRT", L"LOG100", 
				L"LOG1000"});
			this->listBox21->Location = System::Drawing::Point(391, 396);
			this->listBox21->MultiColumn = true;
			this->listBox21->Name = L"listBox21";
			this->listBox21->Size = System::Drawing::Size(475, 36);
			this->listBox21->TabIndex = 3;
			this->listBox21->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox21_SelectedIndexChanged);
			// 
			// label108
			// 
			this->label108->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label108->AutoSize = true;
			this->label108->Location = System::Drawing::Point(804, 6);
			this->label108->Name = L"label108";
			this->label108->Size = System::Drawing::Size(35, 16);
			this->label108->TabIndex = 35;
			this->label108->Text = L"0.0 s";
			// 
			// label103
			// 
			this->label103->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label103->AutoSize = true;
			this->label103->Location = System::Drawing::Point(872, 405);
			this->label103->Name = L"label103";
			this->label103->Size = System::Drawing::Size(74, 16);
			this->label103->TabIndex = 34;
			this->label103->Text = L"Brightness:";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1018, 417);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(15, 16);
			this->label1->TabIndex = 33;
			this->label1->Text = L"1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar1
			// 
			this->trackBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->trackBar1->LargeChange = 10;
			this->trackBar1->Location = System::Drawing::Point(973, 389);
			this->trackBar1->Maximum = 100000;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(104, 45);
			this->trackBar1->TabIndex = 32;
			this->trackBar1->TickFrequency = 10000;
			this->trackBar1->Value = 1;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &Form1::trackBar1_ValueChanged);
			// 
			// button22
			// 
			this->button22->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button22->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button22->Location = System::Drawing::Point(1083, 399);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(118, 26);
			this->button22->TabIndex = 31;
			this->button22->Text = L"SAVE IMAGE";
			this->button22->UseVisualStyleBackColor = false;
			this->button22->Click += gcnew System::EventHandler(this, &Form1::button22_Click);
			// 
			// label102
			// 
			this->label102->AutoSize = true;
			this->label102->Location = System::Drawing::Point(3, 417);
			this->label102->Name = L"label102";
			this->label102->Size = System::Drawing::Size(107, 16);
			this->label102->TabIndex = 26;
			this->label102->Text = L"Dispersion slice:";
			// 
			// pictureBox9
			// 
			this->pictureBox9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox9->Location = System::Drawing::Point(6, 440);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(1195, 122);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox9->TabIndex = 25;
			this->pictureBox9->TabStop = false;
			// 
			// groupBox19
			// 
			this->groupBox19->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox19->Controls->Add(this->button21);
			this->groupBox19->Controls->Add(this->button20);
			this->groupBox19->Controls->Add(this->groupBox23);
			this->groupBox19->Controls->Add(this->button19);
			this->groupBox19->Controls->Add(this->groupBox22);
			this->groupBox19->Controls->Add(this->groupBox21);
			this->groupBox19->Controls->Add(this->groupBox20);
			this->groupBox19->Controls->Add(this->label89);
			this->groupBox19->Controls->Add(this->label88);
			this->groupBox19->Controls->Add(this->label84);
			this->groupBox19->Location = System::Drawing::Point(6, 98);
			this->groupBox19->Name = L"groupBox19";
			this->groupBox19->Size = System::Drawing::Size(966, 285);
			this->groupBox19->TabIndex = 24;
			this->groupBox19->TabStop = false;
			this->groupBox19->Text = L"Data explorer";
			// 
			// button21
			// 
			this->button21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button21->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Lime;
			this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button21->Location = System::Drawing::Point(655, 116);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(118, 72);
			this->button21->TabIndex = 30;
			this->button21->Text = L"GET SLICE";
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &Form1::button21_Click);
			// 
			// button20
			// 
			this->button20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button20->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button20->Location = System::Drawing::Point(838, 24);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(118, 72);
			this->button20->TabIndex = 29;
			this->button20->Text = L"SAVE TXT";
			this->button20->UseVisualStyleBackColor = false;
			this->button20->Click += gcnew System::EventHandler(this, &Form1::button20_Click);
			// 
			// groupBox23
			// 
			this->groupBox23->Controls->Add(this->listBox20);
			this->groupBox23->Location = System::Drawing::Point(779, 102);
			this->groupBox23->Name = L"groupBox23";
			this->groupBox23->Size = System::Drawing::Size(177, 96);
			this->groupBox23->TabIndex = 28;
			this->groupBox23->TabStop = false;
			this->groupBox23->Text = L"Mode:";
			// 
			// listBox20
			// 
			this->listBox20->FormattingEnabled = true;
			this->listBox20->ItemHeight = 16;
			this->listBox20->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Re and Image", L"Amplitude and Phase"});
			this->listBox20->Location = System::Drawing::Point(6, 24);
			this->listBox20->Name = L"listBox20";
			this->listBox20->Size = System::Drawing::Size(164, 36);
			this->listBox20->TabIndex = 0;
			// 
			// button19
			// 
			this->button19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button19->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Lime;
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button19->Location = System::Drawing::Point(838, 209);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(118, 70);
			this->button19->TabIndex = 25;
			this->button19->Text = L"VIEW";
			this->button19->UseVisualStyleBackColor = false;
			this->button19->Click += gcnew System::EventHandler(this, &Form1::button19_Click);
			// 
			// groupBox22
			// 
			this->groupBox22->Controls->Add(this->label98);
			this->groupBox22->Controls->Add(this->maskedTextBox30);
			this->groupBox22->Controls->Add(this->label99);
			this->groupBox22->Controls->Add(this->label100);
			this->groupBox22->Controls->Add(this->label101);
			this->groupBox22->Controls->Add(this->numericUpDown11);
			this->groupBox22->Controls->Add(this->label94);
			this->groupBox22->Controls->Add(this->maskedTextBox29);
			this->groupBox22->Controls->Add(this->label95);
			this->groupBox22->Controls->Add(this->label96);
			this->groupBox22->Controls->Add(this->label97);
			this->groupBox22->Controls->Add(this->numericUpDown10);
			this->groupBox22->Controls->Add(this->label90);
			this->groupBox22->Controls->Add(this->maskedTextBox28);
			this->groupBox22->Controls->Add(this->label92);
			this->groupBox22->Controls->Add(this->label93);
			this->groupBox22->Controls->Add(this->label91);
			this->groupBox22->Controls->Add(this->numericUpDown9);
			this->groupBox22->Location = System::Drawing::Point(372, 24);
			this->groupBox22->Name = L"groupBox22";
			this->groupBox22->Size = System::Drawing::Size(277, 255);
			this->groupBox22->TabIndex = 6;
			this->groupBox22->TabStop = false;
			this->groupBox22->Text = L"Probe:";
			// 
			// label98
			// 
			this->label98->AutoSize = true;
			this->label98->Location = System::Drawing::Point(178, 210);
			this->label98->Name = L"label98";
			this->label98->Size = System::Drawing::Size(37, 16);
			this->label98->TabIndex = 25;
			this->label98->Text = L"m^-1";
			// 
			// maskedTextBox30
			// 
			this->maskedTextBox30->Location = System::Drawing::Point(41, 207);
			this->maskedTextBox30->Name = L"maskedTextBox30";
			this->maskedTextBox30->ReadOnly = true;
			this->maskedTextBox30->Size = System::Drawing::Size(131, 22);
			this->maskedTextBox30->TabIndex = 26;
			this->maskedTextBox30->Text = L"0.0";
			// 
			// label99
			// 
			this->label99->AutoSize = true;
			this->label99->Location = System::Drawing::Point(178, 178);
			this->label99->Name = L"label99";
			this->label99->Size = System::Drawing::Size(61, 16);
			this->label99->TabIndex = 22;
			this->label99->Text = L"arb. units";
			// 
			// label100
			// 
			this->label100->AutoSize = true;
			this->label100->Location = System::Drawing::Point(6, 178);
			this->label100->Name = L"label100";
			this->label100->Size = System::Drawing::Size(25, 16);
			this->label100->TabIndex = 21;
			this->label100->Text = L"Kz:";
			// 
			// label101
			// 
			this->label101->AutoSize = true;
			this->label101->Location = System::Drawing::Point(6, 210);
			this->label101->Name = L"label101";
			this->label101->Size = System::Drawing::Size(25, 16);
			this->label101->TabIndex = 24;
			this->label101->Text = L"Kz:";
			// 
			// numericUpDown11
			// 
			this->numericUpDown11->Location = System::Drawing::Point(41, 176);
			this->numericUpDown11->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			this->numericUpDown11->Name = L"numericUpDown11";
			this->numericUpDown11->Size = System::Drawing::Size(131, 22);
			this->numericUpDown11->TabIndex = 23;
			this->numericUpDown11->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown11_ValueChanged);
			// 
			// label94
			// 
			this->label94->AutoSize = true;
			this->label94->Location = System::Drawing::Point(178, 133);
			this->label94->Name = L"label94";
			this->label94->Size = System::Drawing::Size(37, 16);
			this->label94->TabIndex = 19;
			this->label94->Text = L"m^-1";
			// 
			// maskedTextBox29
			// 
			this->maskedTextBox29->Location = System::Drawing::Point(41, 130);
			this->maskedTextBox29->Name = L"maskedTextBox29";
			this->maskedTextBox29->ReadOnly = true;
			this->maskedTextBox29->Size = System::Drawing::Size(131, 22);
			this->maskedTextBox29->TabIndex = 20;
			this->maskedTextBox29->Text = L"0.0";
			// 
			// label95
			// 
			this->label95->AutoSize = true;
			this->label95->Location = System::Drawing::Point(178, 101);
			this->label95->Name = L"label95";
			this->label95->Size = System::Drawing::Size(61, 16);
			this->label95->TabIndex = 16;
			this->label95->Text = L"arb. units";
			// 
			// label96
			// 
			this->label96->AutoSize = true;
			this->label96->Location = System::Drawing::Point(6, 101);
			this->label96->Name = L"label96";
			this->label96->Size = System::Drawing::Size(26, 16);
			this->label96->TabIndex = 15;
			this->label96->Text = L"Ky:";
			// 
			// label97
			// 
			this->label97->AutoSize = true;
			this->label97->Location = System::Drawing::Point(6, 133);
			this->label97->Name = L"label97";
			this->label97->Size = System::Drawing::Size(26, 16);
			this->label97->TabIndex = 18;
			this->label97->Text = L"Ky:";
			// 
			// numericUpDown10
			// 
			this->numericUpDown10->Location = System::Drawing::Point(41, 99);
			this->numericUpDown10->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			this->numericUpDown10->Name = L"numericUpDown10";
			this->numericUpDown10->Size = System::Drawing::Size(131, 22);
			this->numericUpDown10->TabIndex = 17;
			this->numericUpDown10->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown10_ValueChanged);
			// 
			// label90
			// 
			this->label90->AutoSize = true;
			this->label90->Location = System::Drawing::Point(178, 60);
			this->label90->Name = L"label90";
			this->label90->Size = System::Drawing::Size(37, 16);
			this->label90->TabIndex = 13;
			this->label90->Text = L"m^-1";
			// 
			// maskedTextBox28
			// 
			this->maskedTextBox28->Location = System::Drawing::Point(41, 57);
			this->maskedTextBox28->Name = L"maskedTextBox28";
			this->maskedTextBox28->ReadOnly = true;
			this->maskedTextBox28->Size = System::Drawing::Size(131, 22);
			this->maskedTextBox28->TabIndex = 14;
			this->maskedTextBox28->Text = L"0.0";
			// 
			// label92
			// 
			this->label92->AutoSize = true;
			this->label92->Location = System::Drawing::Point(178, 28);
			this->label92->Name = L"label92";
			this->label92->Size = System::Drawing::Size(61, 16);
			this->label92->TabIndex = 10;
			this->label92->Text = L"arb. units";
			// 
			// label93
			// 
			this->label93->AutoSize = true;
			this->label93->Location = System::Drawing::Point(6, 28);
			this->label93->Name = L"label93";
			this->label93->Size = System::Drawing::Size(25, 16);
			this->label93->TabIndex = 9;
			this->label93->Text = L"Kx:";
			// 
			// label91
			// 
			this->label91->AutoSize = true;
			this->label91->Location = System::Drawing::Point(6, 60);
			this->label91->Name = L"label91";
			this->label91->Size = System::Drawing::Size(25, 16);
			this->label91->TabIndex = 12;
			this->label91->Text = L"Kx:";
			// 
			// numericUpDown9
			// 
			this->numericUpDown9->Location = System::Drawing::Point(41, 26);
			this->numericUpDown9->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, System::Int32::MinValue});
			this->numericUpDown9->Name = L"numericUpDown9";
			this->numericUpDown9->Size = System::Drawing::Size(131, 22);
			this->numericUpDown9->TabIndex = 11;
			this->numericUpDown9->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown9_ValueChanged);
			// 
			// groupBox21
			// 
			this->groupBox21->Controls->Add(this->listBox17);
			this->groupBox21->Controls->Add(this->listBox18);
			this->groupBox21->Controls->Add(this->listBox19);
			this->groupBox21->Location = System::Drawing::Point(156, 24);
			this->groupBox21->Name = L"groupBox21";
			this->groupBox21->Size = System::Drawing::Size(210, 255);
			this->groupBox21->TabIndex = 5;
			this->groupBox21->TabStop = false;
			this->groupBox21->Text = L"Averaging method:";
			// 
			// listBox17
			// 
			this->listBox17->FormattingEnabled = true;
			this->listBox17->ItemHeight = 16;
			this->listBox17->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"REAL SPACE", L"COMPLEX AMPLITUDE"});
			this->listBox17->Location = System::Drawing::Point(21, 185);
			this->listBox17->Name = L"listBox17";
			this->listBox17->Size = System::Drawing::Size(168, 36);
			this->listBox17->TabIndex = 2;
			this->listBox17->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox17_SelectedIndexChanged);
			// 
			// listBox18
			// 
			this->listBox18->FormattingEnabled = true;
			this->listBox18->ItemHeight = 16;
			this->listBox18->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"REAL SPACE", L"COMPLEX AMPLITUDE"});
			this->listBox18->Location = System::Drawing::Point(21, 108);
			this->listBox18->Name = L"listBox18";
			this->listBox18->Size = System::Drawing::Size(168, 36);
			this->listBox18->TabIndex = 1;
			this->listBox18->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox18_SelectedIndexChanged);
			// 
			// listBox19
			// 
			this->listBox19->FormattingEnabled = true;
			this->listBox19->ItemHeight = 16;
			this->listBox19->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"REAL SPACE", L"COMPLEX AMPLITUDE"});
			this->listBox19->Location = System::Drawing::Point(19, 34);
			this->listBox19->Name = L"listBox19";
			this->listBox19->Size = System::Drawing::Size(170, 36);
			this->listBox19->TabIndex = 0;
			this->listBox19->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox19_SelectedIndexChanged);
			// 
			// groupBox20
			// 
			this->groupBox20->Controls->Add(this->listBox16);
			this->groupBox20->Controls->Add(this->listBox15);
			this->groupBox20->Controls->Add(this->listBox14);
			this->groupBox20->Location = System::Drawing::Point(57, 24);
			this->groupBox20->Name = L"groupBox20";
			this->groupBox20->Size = System::Drawing::Size(93, 255);
			this->groupBox20->TabIndex = 4;
			this->groupBox20->TabStop = false;
			this->groupBox20->Text = L"Averaging";
			// 
			// listBox16
			// 
			this->listBox16->FormattingEnabled = true;
			this->listBox16->ItemHeight = 16;
			this->listBox16->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"NO", L"YES"});
			this->listBox16->Location = System::Drawing::Point(21, 185);
			this->listBox16->Name = L"listBox16";
			this->listBox16->Size = System::Drawing::Size(50, 36);
			this->listBox16->TabIndex = 2;
			this->listBox16->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox16_SelectedIndexChanged);
			// 
			// listBox15
			// 
			this->listBox15->FormattingEnabled = true;
			this->listBox15->ItemHeight = 16;
			this->listBox15->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"NO", L"YES"});
			this->listBox15->Location = System::Drawing::Point(21, 108);
			this->listBox15->Name = L"listBox15";
			this->listBox15->Size = System::Drawing::Size(50, 36);
			this->listBox15->TabIndex = 1;
			this->listBox15->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox15_SelectedIndexChanged);
			// 
			// listBox14
			// 
			this->listBox14->FormattingEnabled = true;
			this->listBox14->ItemHeight = 16;
			this->listBox14->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"NO", L"YES"});
			this->listBox14->Location = System::Drawing::Point(19, 34);
			this->listBox14->Name = L"listBox14";
			this->listBox14->Size = System::Drawing::Size(52, 36);
			this->listBox14->TabIndex = 0;
			this->listBox14->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox14_SelectedIndexChanged);
			// 
			// label89
			// 
			this->label89->AutoSize = true;
			this->label89->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label89->Location = System::Drawing::Point(7, 221);
			this->label89->Name = L"label89";
			this->label89->Size = System::Drawing::Size(35, 17);
			this->label89->TabIndex = 0;
			this->label89->Text = L"Z ->";
			// 
			// label88
			// 
			this->label88->AutoSize = true;
			this->label88->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label88->Location = System::Drawing::Point(6, 143);
			this->label88->Name = L"label88";
			this->label88->Size = System::Drawing::Size(35, 17);
			this->label88->TabIndex = 0;
			this->label88->Text = L"Y ->";
			// 
			// label84
			// 
			this->label84->AutoSize = true;
			this->label84->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label84->Location = System::Drawing::Point(6, 67);
			this->label84->Name = L"label84";
			this->label84->Size = System::Drawing::Size(36, 17);
			this->label84->TabIndex = 0;
			this->label84->Text = L"X ->";
			// 
			// button18
			// 
			this->button18->Enabled = false;
			this->button18->Location = System::Drawing::Point(6, 6);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(164, 86);
			this->button18->TabIndex = 23;
			this->button18->Text = L"CALCULATE 3D DISPERSION";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Visible = false;
			this->button18->Click += gcnew System::EventHandler(this, &Form1::button18_Click);
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->maskedTextBox14);
			this->tabPage7->Location = System::Drawing::Point(4, 68);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(1224, 568);
			this->tabPage7->TabIndex = 6;
			this->tabPage7->Text = L"DEBUG OUTPUT";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// maskedTextBox14
			// 
			this->maskedTextBox14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maskedTextBox14->Location = System::Drawing::Point(6, 6);
			this->maskedTextBox14->Name = L"maskedTextBox14";
			this->maskedTextBox14->Size = System::Drawing::Size(0, 22);
			this->maskedTextBox14->TabIndex = 0;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripProgressBar1, 
				this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 690);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1256, 22);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Maximum = 127;
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(100, 16);
			this->toolStripProgressBar1->Value = 100;
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(38, 17);
			this->toolStripStatusLabel1->Text = L"Done.";
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(1195, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(22, 23);
			this->button4->TabIndex = 0;
			this->button4->Text = L"_";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox4->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox4->Location = System::Drawing::Point(3, 3);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(414, 394);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 0;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox5->BackColor = System::Drawing::Color::Gainsboro;
			this->pictureBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox5->Location = System::Drawing::Point(3, 3);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(414, 394);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 0;
			this->pictureBox5->TabStop = false;
			// 
			// listBox10
			// 
			this->listBox10->FormattingEnabled = true;
			this->listBox10->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"XT-XF", L"YT-YF", L"ZT-ZF"});
			this->listBox10->Location = System::Drawing::Point(33, 24);
			this->listBox10->Name = L"listBox10";
			this->listBox10->Size = System::Drawing::Size(51, 43);
			this->listBox10->TabIndex = 0;
			// 
			// linkLabel1
			// 
			this->linkLabel1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->linkLabel1->LinkBehavior = System::Windows::Forms::LinkBehavior::AlwaysUnderline;
			this->linkLabel1->Location = System::Drawing::Point(443, 654);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(370, 18);
			this->linkLabel1->TabIndex = 4;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Please submit bugs and queries to M. Dvornik, UniEXE";
			this->linkLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Form1::linkLabel1_LinkClicked);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 89);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 89);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1256, 712);
			this->ControlBox = false;
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"semargl3";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox25->ResumeLayout(false);
			this->groupBox25->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown17))->EndInit();
			this->groupBox24->ResumeLayout(false);
			this->groupBox24->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown12))->EndInit();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->EndInit();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->groupBox11->ResumeLayout(false);
			this->tabPage8->ResumeLayout(false);
			this->tabPage8->PerformLayout();
			this->groupBox28->ResumeLayout(false);
			this->groupBox26->ResumeLayout(false);
			this->groupBox14->ResumeLayout(false);
			this->groupBox14->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown7))->EndInit();
			this->groupBox13->ResumeLayout(false);
			this->groupBox15->ResumeLayout(false);
			this->groupBox12->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->groupBox27->ResumeLayout(false);
			this->groupBox27->PerformLayout();
			this->groupBox18->ResumeLayout(false);
			this->groupBox17->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
			this->groupBox16->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->EndInit();
			this->groupBox19->ResumeLayout(false);
			this->groupBox19->PerformLayout();
			this->groupBox23->ResumeLayout(false);
			this->groupBox22->ResumeLayout(false);
			this->groupBox22->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown9))->EndInit();
			this->groupBox21->ResumeLayout(false);
			this->groupBox20->ResumeLayout(false);
			this->tabPage7->ResumeLayout(false);
			this->tabPage7->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 richTextBox1->AppendText("semargl3 software has been started...\n");
			 cDataContainer::p_ExtractingMethod.m_IsNormaliseByMs = checkBox1->Checked;
			 cDataContainer::p_ExtractingMethod.m_PreprocessingMethod = 1;

			 listBox2->SelectedIndex = mcSettings::m_aoFFTWindowType;
			 maskedTextBox19->Text = Convert::ToString(mcSettings::m_aoKeiserCoeff);

			 listBox3->SelectedIndex = mcSettings::m_eiFormat;
			 listBox4->SelectedIndex = cProbe::ProbeType;
			 
			 if (cProbe::ProbeType == 0)
			 {
				 numericUpDown1->Enabled = false;
				 numericUpDown2->Enabled = false;
				 numericUpDown3->Enabled = false;
				 numericUpDown4->Enabled = false;
				 numericUpDown5->Enabled = false;
				 numericUpDown6->Enabled = false;

				 numericUpDown1->Value = 0;
				 numericUpDown2->Value = 0;
				 numericUpDown3->Value = 0;

				 numericUpDown4->Value = cDataContainer::SimulationsData.s_params.m_SizeX;
				 numericUpDown5->Value = cDataContainer::SimulationsData.s_params.m_SizeY;
				 numericUpDown6->Value = cDataContainer::SimulationsData.s_params.m_SizeZ;
			 
			 }

			 switch(mcSettings::m_prViewPortProj)
			 {
			 case 0:
			     radioButton5->Checked = true;
				 break;
			 case 1:
				 radioButton6->Checked = true;
				 break;
			 case 2:
				 radioButton9->Checked = true;
				 break;
			 }

			 listBox6->SelectedIndex = mcSettings::m_etExportFormat;
			 listBox5->SelectedIndex = mcSettings::m_trAveragingPlane;

			 listBox7->SelectedIndex = mcSettings::m_mmdProjType;
			 listBox8->SelectedIndex = mcSettings::m_mmdMode;
			 listBox9->SelectedIndex = mcSettings::m_mmdBSMode;
			 listBox11->SelectedIndex = mcSettings::m_fdaMethod;
			 listBox12->SelectedIndex = mcSettings::m_fdaMode;

			 long long separator = 200; // pixels
			 long long sizex = this->Size.Width;
			 long long pwidth = (sizex - separator)/2;
			 long long xcoord = 3 * separator/4 + pwidth;

			 this->panel3->Width = pwidth;
			 this->panel4->Width = pwidth;
			 this->panel1->Width = pwidth;
			 this->panel2->Width = pwidth;

			 long long ycoordp3 = this->panel3->Location.Y;
			 long long ycoordp2 = this->panel2->Location.Y;

			 System::Drawing::Point newcoordp3 = System::Drawing::Point(xcoord, ycoordp3);
			 System::Drawing::Point newcoordp2 = System::Drawing::Point(xcoord, ycoordp2);
			 this->panel3->Location = newcoordp3; 
			 this->panel2->Location = newcoordp2;

			 numericUpDown8->Minimum = 0;
			 numericUpDown8->Value = 0;
			 listBox13->SelectedIndex = mcSettings::m_fdaAvgMethod;

			 listBox14->SelectedIndex = mcSettings::m_dcIsAvgX;
			 listBox15->SelectedIndex = mcSettings::m_dcIsAvgY;
			 listBox16->SelectedIndex = mcSettings::m_dcIsAvgZ;

			 listBox17->SelectedIndex = mcSettings::m_dcAvgMethodX;
			 listBox18->SelectedIndex = mcSettings::m_dcAvgMethodY;
			 listBox19->SelectedIndex = mcSettings::m_dcAvgMethodZ;
			 listBox21->SelectedIndex = mcSettings::m_dcColorScale;
			 listBox20->SelectedIndex = mcSettings::m_dcMode;
			 linkLabel1->Links->Add(0,0,"http://www.magnonics.org/");
			 trackBar1->Value = mcSettings::m_dcImageBr;
			 toolStripButton2->Enabled = !(checkBox2->Checked);
			 listBox22->SelectedIndex = mcSettings::m_trFRSMode;
			 trackBar3->Value = mcSettings::m_trFRSImageBr ;
			 label107->Text = Convert::ToString(mcSettings::m_trFRSImageBr);
			 calcpart_off();
			 array<String^>^ args = Environment::GetCommandLineArgs();
			 long long rank = args->GetLongLength(0);
			 if (rank > 1)
			 {
				 this->Visible = false;
				 Console::WriteLine("semargl3 console mode.\n");
			 }

		 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 //overrinding windows forms "CLOSE" button
				 this->Close();
			 }
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton4->Checked) 
			 {
				cDataContainer::p_ExtractingMethod.m_MagnetizationComponent = 3;
				 radioButton7->Checked = true;
			 }
		 }
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton1->Checked) cDataContainer::p_ExtractingMethod.m_MagnetizationComponent = 0;
		 }
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton2->Checked) cDataContainer::p_ExtractingMethod.m_MagnetizationComponent = 1;
		 }
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton3->Checked) cDataContainer::p_ExtractingMethod.m_MagnetizationComponent = 2;
		 }

// Manage the file name of the file contaning spatial profile of the ground state magnetization profile
// STARTS HERE
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ OpenStaticFile = gcnew OpenFileDialog();
			 OpenStaticFile->Title = L"Open file with the spatial profile of the magnetization of the ground state.";
			 OpenStaticFile->Multiselect = false;
			 OpenStaticFile->Filter = "Static file (*.stc) |*.stc| All files (*.*)|*.*";
			 OpenStaticFile->DefaultExt = "stc";

			 if (OpenStaticFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {

				maskedTextBox1->Text = OpenStaticFile->FileName;
				richTextBox1->AppendText("The static file name has been setted to:\t");
				richTextBox1->AppendText(maskedTextBox1->Text);
				richTextBox1->AppendText("\n");

			    pin_ptr<const wchar_t> wch = PtrToStringChars(maskedTextBox1->Text);
				size_t convertedChars = 0;
				size_t  sizeInBytes = ((maskedTextBox1->Text->Length + 1) * 2);
				errno_t err = 0;
				cDataContainer::m_pGroundStateFileName = (char *)malloc(sizeInBytes);

				err = wcstombs_s(&convertedChars, 
								cDataContainer::m_pGroundStateFileName, sizeInBytes,
								wch, sizeInBytes);
				if (err !=0)
				{
					Windows::Forms::MessageBox::Show("Error while marshaling data from Managed to Native code");
					return;
				}
				if (checkBox2->Checked)
				{
					String^ datapath = Path::GetDirectoryName(OpenStaticFile->FileName);
					get_simdata(datapath);
				}


			 }

		 }
//private: System::Void maskedTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
//
//				richTextBox1->AppendText("The static file name has been changed to:\t");
//				richTextBox1->AppendText(maskedTextBox1->Text);
//				richTextBox1->AppendText("\n");
//
//				pin_ptr<const wchar_t> wch = PtrToStringChars(maskedTextBox1->Text);
//				size_t convertedChars = 0;
//				size_t  sizeInBytes = ((maskedTextBox1->Text->Length + 1) * 2);
//				errno_t err = 0;
//				cDataContainer::m_pGroundStateFileName = (char *)malloc(sizeInBytes);
//
//				err = wcstombs_s(&convertedChars, 
//								cDataContainer::m_pGroundStateFileName, sizeInBytes,
//								wch, sizeInBytes);
//				if (err !=0)
//				{
//					Windows::Forms::MessageBox::Show("Error while marshaling data from Managed to Native code");
//				}
//		 }
// END

// Manage the path to the folder conatining temporal magnetization profiles
// STARTS HERE

private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
			 FolderBrowserDialog^ BrowseDynamicsFolder = gcnew FolderBrowserDialog();
			 BrowseDynamicsFolder->ShowNewFolderButton = false;
			 BrowseDynamicsFolder->Description = L"Please locate the folder containing the temporal magnetization profiles";
			 if (BrowseDynamicsFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 if (Directory::Exists(BrowseDynamicsFolder->SelectedPath))
				 {

					//pin_ptr<const wchar_t> wch = PtrToStringChars(maskedTextBox1->Text);
					//size_t convertedChars = 0;
					//size_t  sizeInBytes = ((maskedTextBox1->Text->Length + 1) * 2);
					//errno_t err = 0;
					//cDataContainer::m_pGroundStateFileName = (char *)malloc(sizeInBytes);

					//err = wcstombs_s(&convertedChars, 
					//				cDataContainer::m_pGroundStateFileName, sizeInBytes,
					//				wch, sizeInBytes);
					//if (err !=0)
					//{
					//	Windows::Forms::MessageBox::Show("Error while marshaling data from Managed to Native code");
					//}
					String^ datapath = BrowseDynamicsFolder->SelectedPath;
					get_simdata(datapath);
				 }
				 else 
				 {
					maskedTextBox13->Text = Convert::ToString(0);
					Windows::Forms::MessageBox::Show("Specified folder cannot be located.");
				 }			 
			 }
		 }
// END
private: System::Void get_simdata(String^ path)
		 {			
					maskedTextBox2->Text = path;
					richTextBox1->AppendText("The path to the dynamics files has been setted to:\t");
					richTextBox1->AppendText(path);
					richTextBox1->AppendText("\n");

					array<String^>^ str = Directory::GetFiles(path, "*.ovf");
					Array::Sort(str); // to ensure that correct order of files is preserved
					long long FileCount = str->GetLength(0);
					cDataContainer::m_nNumberOfDynamicFiles = FileCount;

					maskedTextBox13->Text = Convert::ToString(FileCount);
				
					richTextBox1->AppendText(Convert::ToString(FileCount));

					richTextBox1->AppendText(" *.omf files have been founder in ");
					richTextBox1->AppendText(maskedTextBox2->Text);
					richTextBox1->AppendText("\n");

					cDataContainer::m_pDynamicFileNames = (char**) new char*[FileCount];

					for (long long i = 0; i < FileCount; i++)
					{
						pin_ptr<const wchar_t> wch = PtrToStringChars(str[i]);
						size_t convertedChars = 0;
						size_t sizeInBytes = ((str[i]->Length + 1) * 2);
						errno_t err = 0;
						cDataContainer::m_pDynamicFileNames[i] = (char*) new char[sizeInBytes];		//(char*)calloc(sizeInBytes,sizeof(char));
						//cDataContainer::m_pDynamicFileNames[i] = (char*)new char[sizeInBytes];
						err = wcstombs_s(&convertedChars, 
							cDataContainer::m_pDynamicFileNames[i], sizeInBytes,
										wch, sizeInBytes);
						if (err !=0)
						{
							Windows::Forms::MessageBox::Show("Error while marshaling data from Managed to Native code");
						}
					}
					//Extracting parameters of the simulations
					if (cReader::ProbeParametersOfSimulations(cDataContainer::m_pGroundStateFileName,
																cDataContainer::m_pDynamicFileNames, 
																cDataContainer::m_nNumberOfDynamicFiles,
																&cDataContainer::SimulationsData)==0)
					{
						cDataContainer::SimulationsData.SetParametersFlag();
						// SET APPORATE FIELDS ON THE MAIN FORM
						 maskedTextBox3->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_SizeX);
						 maskedTextBox4->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_SizeY);
						 maskedTextBox5->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_SizeZ);

						 maskedTextBox6->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_CellSizeX);		
						 maskedTextBox7->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_CellSizeY);
						 maskedTextBox8->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_CellSizeZ);
							
						 String^ t_str = marshal_as<String^>(cDataContainer::SimulationsData.s_params.m_pMIFFileName);
						 maskedTextBox9->Text = t_str; 
						 maskedTextBox10->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_SimulationsTotalTime);
						 maskedTextBox11->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_StageTime);
						 maskedTextBox12->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_MsMax);
							
						 listBox1->Items->Clear();

						 for (long long i=0;i<cDataContainer::SimulationsData.s_params.m_MsCount;i++)
						 {
							 listBox1->Items->Add(Convert::ToString(cDataContainer::SimulationsData.s_params.m_pMs[i]));
						 }
					}
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 cDataContainer::p_ExtractingMethod.m_IsNormaliseByMs = checkBox1->Checked;
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Load the data, pre- and post- processing will be applied as a part of the method
			 
			 if (cDataContainer::SimulationsData.GetParametersFlag()==1)
			 {
				 //Allocate buffers
				 cDataContainer::SimulationsData.AllocateBuffers();
				 Thread^ loader = gcnew Thread(gcnew ThreadStart(&mcSample::LoadTheData));
				 loader->Start();
				 toolStripProgressBar1->Value = 0;
				 this->Enabled = false;
				 while (loader->IsAlive)
				 {
					 toolStripProgressBar1->Value = (toolStripProgressBar1->Value + 5) & toolStripProgressBar1->Maximum;
					 Thread::Sleep(100);
				 }
				 toolStripProgressBar1->Value = toolStripProgressBar1->Maximum;
				 /*if (cReader::LoadOMFData(cDataContainer::m_pGroundStateFileName,
					 cDataContainer::m_pDynamicFileNames,
					 cDataContainer::m_nNumberOfDynamicFiles,
					 &cDataContainer::SimulationsData,
					 &cDataContainer::p_ExtractingMethod)==0)*/
				 long long check =  cDataContainer::SimulationsData.ValidateRealData();

				 if (cDataContainer::SimulationsData.m_IsLoaded != 0 && check == 0)
				 {
//#ifdef _DEBUG
//					 cDataContainer::SimulationsData.dbgDoDataAveraging();
//					 for (long long i=0;i<cDataContainer::SimulationsData.s_params.m_NumberOfTimeSteps;i++)
//					 {
//						 maskedTextBox14->AppendText(Convert::ToString(cDataContainer::SimulationsData.avgdata[i].Re));
//						 maskedTextBox14->AppendText("\n");
//
//					 }
//					 
//#endif
					 maskedTextBox15->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_SizeX);
					 mcSettings::m_etPointsX = cDataContainer::SimulationsData.s_params.m_SizeX;
					 maskedTextBox16->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_SizeY);
					 mcSettings::m_etPointsY = cDataContainer::SimulationsData.s_params.m_SizeY;
					 maskedTextBox17->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_SizeZ);
					 mcSettings::m_etPointsZ = cDataContainer::SimulationsData.s_params.m_SizeZ;
					 maskedTextBox18->Text = Convert::ToString(cDataContainer::SimulationsData.s_params.m_NumberOfTimeSteps);
					 mcSettings::m_etPointsT = cDataContainer::SimulationsData.s_params.m_NumberOfTimeSteps;

					 numericUpDown1->Maximum = cDataContainer::SimulationsData.s_params.m_SizeX;
					 numericUpDown4->Maximum = cDataContainer::SimulationsData.s_params.m_SizeX;
					 numericUpDown2->Maximum = cDataContainer::SimulationsData.s_params.m_SizeY;
					 numericUpDown5->Maximum = cDataContainer::SimulationsData.s_params.m_SizeY;
					 numericUpDown3->Maximum = cDataContainer::SimulationsData.s_params.m_SizeZ;
					 numericUpDown6->Maximum = cDataContainer::SimulationsData.s_params.m_SizeZ;
					 cProbe::Reset();

					 mcImage::GenerateSampleProfileImage();
					 pictureBox1->Image = mcSample::sample_xy;

					 if (cProbe::ProbeType == 0)
					 {

						 numericUpDown1->Value = 0;
						 numericUpDown2->Value = 0;
						 numericUpDown3->Value = 0;

						 numericUpDown4->Value = cDataContainer::SimulationsData.s_params.m_SizeX;
						 numericUpDown5->Value = cDataContainer::SimulationsData.s_params.m_SizeY;
						 numericUpDown6->Value = cDataContainer::SimulationsData.s_params.m_SizeZ;
					 
					 }
					 numericUpDown7->Maximum = cDataContainer::SimulationsData.s_params.m_NumberOfTimeSteps - 1;
					 numericUpDown8->Maximum = cDataContainer::SimulationsData.s_params.m_SizeZ - 1;
					 numericUpDown8->Value = 0;
					 numericUpDown8->Minimum = 0;
					 calcpart_off();

				 }
				 else
				 {
					// ERROR WHILE LOADING
					Windows::Forms::MessageBox::Show("Error while attempting to load or pre-/post- processing the data.");
				 }
				 this->Enabled = true;
			 }
			 
		 }
private: System::Void label28_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void maskedTextBox15_Validated(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_etPointsX = Convert::ToInt32(Math::Truncate(Convert::ToInt32(maskedTextBox15->Text)));
		 }
private: System::Void maskedTextBox16_Validated(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_etPointsY = Convert::ToInt32(Math::Truncate(Convert::ToInt32(maskedTextBox16->Text)));
		 }
private: System::Void maskedTextBox17_Validated(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_etPointsZ = Convert::ToInt32(Math::Truncate(Convert::ToInt32(maskedTextBox17->Text)));
		 }
private: System::Void maskedTextBox18_Validated(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_etPointsT = Convert::ToInt32(Math::Truncate(Convert::ToInt32(maskedTextBox18->Text)));
		 }
private: System::Void maskedTextBox19_Validated(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_aoKeiserCoeff = Convert::ToDouble(maskedTextBox19->Text);
		 }
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 double x0_m = Convert::ToDouble(numericUpDown1->Value) * cDataContainer::SimulationsData.s_params.m_CellSizeX;
			 cProbe::X0 = Convert::ToInt32(numericUpDown1->Value);
			 cProbe::X0_m = x0_m;
			 cProbe::sizeX = Math::Abs(cProbe::X0 - cProbe::X1);
			 cProbe::sizeX_m = cProbe::sizeX * cDataContainer::SimulationsData.s_params.m_CellSizeX;
			 maskedTextBox20->Text = Convert::ToString(x0_m);
			 mcImage::DrawProbe();
			 switch(mcSettings::m_prViewPortProj)
			 {
			 case 0:
				 pictureBox1->Image = mcSample::sample_xy;
				 break;
			 case 1:
				 pictureBox1->Image = mcSample::sample_xz;
				 break;
			 case 2:
				 pictureBox1->Image = mcSample::sample_yz;
				 break;
			 }
		 }
private: System::Void numericUpDown4_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 double x1_m = Convert::ToDouble(numericUpDown4->Value) * cDataContainer::SimulationsData.s_params.m_CellSizeX;
			 cProbe::X1 = Convert::ToInt32(numericUpDown4->Value);
			 cProbe::X1_m = x1_m;
			 cProbe::sizeX = Math::Abs(cProbe::X0 - cProbe::X1);
			 cProbe::sizeX_m = cProbe::sizeX * cDataContainer::SimulationsData.s_params.m_CellSizeX;
			 maskedTextBox23->Text = Convert::ToString(x1_m);
			 DrawProbe();
		 }
private: System::Void DrawProbe()
		 {
			 mcImage::DrawProbe();
			 switch(mcSettings::m_prViewPortProj)
			 {
			 case 0:
				 pictureBox1->Image = mcSample::sample_xy;
				 break;
			 case 1:
				 pictureBox1->Image = mcSample::sample_xz;
				 break;
			 case 2:
				 pictureBox1->Image = mcSample::sample_yz;
				 break;
			 }
		 }
private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 double y0_m = Convert::ToDouble(numericUpDown2->Value) * cDataContainer::SimulationsData.s_params.m_CellSizeY;
			 cProbe::Y0 = Convert::ToInt32(numericUpDown2->Value);
			 cProbe::Y0_m = y0_m;
			 cProbe::sizeY = Math::Abs(cProbe::Y0 - cProbe::Y1);
			 cProbe::sizeY_m = cProbe::sizeY * cDataContainer::SimulationsData.s_params.m_CellSizeY;
			 maskedTextBox21->Text = Convert::ToString(y0_m);
			 mcImage::DrawProbe();
			 switch(mcSettings::m_prViewPortProj)
			 {
			 case 0:
				 pictureBox1->Image = mcSample::sample_xy;
				 break;
			 case 1:
				 pictureBox1->Image = mcSample::sample_xz;
				 break;
			 case 2:
				 pictureBox1->Image = mcSample::sample_yz;
				 break;
			 }
		 }
private: System::Void numericUpDown5_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 double y1_m = Convert::ToDouble(numericUpDown5->Value) * cDataContainer::SimulationsData.s_params.m_CellSizeY;
			 cProbe::Y1 = Convert::ToInt32(numericUpDown5->Value);
			 cProbe::Y1_m = y1_m;
			 cProbe::sizeY = Math::Abs(cProbe::Y0 - cProbe::Y1);
			 cProbe::sizeY_m = cProbe::sizeY * cDataContainer::SimulationsData.s_params.m_CellSizeY;
			 maskedTextBox24->Text = Convert::ToString(y1_m);
			 mcImage::DrawProbe();
			 switch(mcSettings::m_prViewPortProj)
			 {
			 case 0:
				 pictureBox1->Image = mcSample::sample_xy;
				 break;
			 case 1:
				 pictureBox1->Image = mcSample::sample_xz;
				 break;
			 case 2:
				 pictureBox1->Image = mcSample::sample_yz;
				 break;
			 }
		 }
private: System::Void numericUpDown3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 double z0_m = Convert::ToDouble(numericUpDown3->Value) * cDataContainer::SimulationsData.s_params.m_CellSizeZ;
			 cProbe::Z0 = Convert::ToInt32(numericUpDown3->Value);
			 cProbe::Z0_m = z0_m;
			 cProbe::sizeZ = Math::Abs(cProbe::Z0 - cProbe::Z1);
			 cProbe::sizeZ_m = cProbe::sizeZ * cDataContainer::SimulationsData.s_params.m_CellSizeZ;
			 maskedTextBox22->Text = Convert::ToString(z0_m);
			 mcImage::DrawProbe();
			 switch(mcSettings::m_prViewPortProj)
			 {
			 case 0:
				 pictureBox1->Image = mcSample::sample_xy;
				 break;
			 case 1:
				 pictureBox1->Image = mcSample::sample_xz;
				 break;
			 case 2:
				 pictureBox1->Image = mcSample::sample_yz;
				 break;
			 }
		 }
private: System::Void numericUpDown6_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 double z1_m = Convert::ToDouble(numericUpDown6->Value) * cDataContainer::SimulationsData.s_params.m_CellSizeZ;
			 cProbe::Z1 = Convert::ToInt32(numericUpDown6->Value);
			 cProbe::Z1_m = z1_m;
			 cProbe::sizeZ = Math::Abs(cProbe::Z0 - cProbe::Z1);
			 cProbe::sizeZ_m = cProbe::sizeZ * cDataContainer::SimulationsData.s_params.m_CellSizeZ;
			 maskedTextBox25->Text = Convert::ToString(z1_m);
			 mcImage::DrawProbe();
			 switch(mcSettings::m_prViewPortProj)
			 {
			 case 0:
				 pictureBox1->Image = mcSample::sample_xy;
				 break;
			 case 1:
				 pictureBox1->Image = mcSample::sample_xz;
				 break;
			 case 2:
				 pictureBox1->Image = mcSample::sample_yz;
				 break;
			 }
		 }
private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton5->Checked)
			 {
				 mcSettings::m_prViewPortProj = 0;
				 mcImage::DrawProbe();
				 pictureBox1->Image = mcSample::sample_xy;
				 
				 //apply probe as well
			 }
		 }
private: System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton6->Checked)
			 {
				 mcSettings::m_prViewPortProj = 1;
				 mcImage::DrawProbe();
				 pictureBox1->Image = mcSample::sample_xz;
				 //apply probe as well
			 }

		 }
private: System::Void radioButton9_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton9->Checked)
			 {
				 mcSettings::m_prViewPortProj = 2;
				 mcImage::DrawProbe();
				 pictureBox1->Image = mcSample::sample_yz;
				 //apply probe as well
			 }

		 }
private: System::Void listBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 cProbe::ProbeType = listBox4->SelectedIndex;

			 switch(cProbe::ProbeType)
			 {
			 case 0:
				 numericUpDown1->Enabled = false;
				 numericUpDown2->Enabled = false;
				 numericUpDown3->Enabled = false;
				 numericUpDown4->Enabled = false;
				 numericUpDown5->Enabled = false;
				 numericUpDown6->Enabled = false;

				 numericUpDown1->Value = 0;
				 numericUpDown2->Value = 0;
				 numericUpDown3->Value = 0;

				 numericUpDown4->Value = cDataContainer::SimulationsData.s_params.m_SizeX;
				 numericUpDown5->Value = cDataContainer::SimulationsData.s_params.m_SizeY;
				 numericUpDown6->Value = cDataContainer::SimulationsData.s_params.m_SizeZ;
				 break;
			 case 1:
				 numericUpDown1->Enabled = true;
				 numericUpDown2->Enabled = true;
				 numericUpDown3->Enabled = true;
				 numericUpDown4->Enabled = true;
				 numericUpDown5->Enabled = true;
				 numericUpDown6->Enabled = true;
				 numericUpDown1->Value = 0;
				 numericUpDown2->Value = 0;
				 numericUpDown3->Value = 0;

				 numericUpDown4->Value = 0;
				 numericUpDown5->Value = 0;
				 numericUpDown6->Value = 0;
				 break;

			 }

		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 gen_probe();
		 }
private: System::Void gen_probe()
		 {
			 long long fsizeX = cDataContainer::SimulationsData.s_params.m_SizeX;
			 long long fsizeY = cDataContainer::SimulationsData.s_params.m_SizeY;
			 long long fsizeZ = cDataContainer::SimulationsData.s_params.m_SizeZ;
			 double csx = cDataContainer::SimulationsData.s_params.m_CellSizeX;
			 double csy = cDataContainer::SimulationsData.s_params.m_CellSizeY;
			 double csz = cDataContainer::SimulationsData.s_params.m_CellSizeZ;

			 cProbe::Create(fsizeX, fsizeY, fsizeZ, csx, csy, csz);
			 switch(mcSettings::m_mmdProjType)
			 {
			 case 0:
				 numericUpDown8->Maximum = cProbe::sizeZ - 1;
				 break;
			 case 1:
				 numericUpDown8->Maximum = cProbe::sizeY - 1;
				 break;
			 case 2:
				 numericUpDown8->Maximum = cProbe::sizeX - 1;
				 break;
			 }
			 numericUpDown9->Maximum = cProbe::sizeX - 1;
			 numericUpDown10->Maximum = cProbe::sizeY - 1;
			 numericUpDown11->Maximum = cProbe::sizeZ - 1;
			 DrawProbe();

		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 //
			 this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
		 }

private: System::Void listBox6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_etExportFormat = listBox6->SelectedIndex;
		 }
private: System::Void listBox5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_trAveragingPlane = listBox5->SelectedIndex;
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 long long avg_plane = mcSettings::m_trAveragingPlane;
			 switch(avg_plane)
			 {
			 case 0:
				 label66->Text = L"XT";
				 label67->Text = L"XF";
				 break;
			 case 1:
				 label66->Text = L"YT";
				 label67->Text = L"YF";
				 break;
			 case 2:
				 label66->Text = L"ZT";
				 label67->Text = L"ZF";
				 break;
			 }
			 //mcSample::DoTRSandFRS();
			 Thread^ trs_fft = gcnew Thread(gcnew ThreadStart(&mcSample::DoTRSandFRS));
			 trs_fft->Start();
			 this->toolStripProgressBar1->Value = 0;
			 this->Enabled = false;
			 while (trs_fft->IsAlive)
			 {
				toolStripProgressBar1->Value = (toolStripProgressBar1->Value + 5) & toolStripProgressBar1->Maximum;
				Thread::Sleep(100);
			 }		 
			 pictureBox2->Image = mcSample::trs_image;
			 pictureBox3->Image = mcSample::frs_image;
			 this->Enabled = true;
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->SaveImageToFile(mcSample::trs_image, L"");
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->SaveImageToFile(mcSample::frs_image, L"");
}

private: System::Void SaveImageToFile(System::Drawing::Bitmap^ Image, System::String^ def_filename)
		 {
			 SaveFileDialog^ Save2DTRSFile = gcnew SaveFileDialog();
			 Save2DTRSFile->Title = L"Save 2D image";
			 Save2DTRSFile->Filter = this->GetImageEXTWildCard();
			 Save2DTRSFile->FileName = def_filename;
			 if (Save2DTRSFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 Image->Save(Save2DTRSFile->FileName, this->GetImageFormat());
			 }
		 }
private: System::Drawing::Imaging::ImageFormat^ GetImageFormat() {
			 System::Drawing::Imaging::ImageFormat^ format = System::Drawing::Imaging::ImageFormat::Tiff;
			 switch(mcSettings::m_etExportFormat)
			 {
			 case 0:
				 format = System::Drawing::Imaging::ImageFormat::Tiff;
				 break;
			 case 1:
				 format = System::Drawing::Imaging::ImageFormat::Png;
				 break;
			 case 2:
				 format = System::Drawing::Imaging::ImageFormat::Bmp;
				 break;
			 }
			 return format;
		 }

private: System::String^ GetImageEXTWildCard()
		 {
			 System::String^ ext = "TIFF (*.tif) | *.tif";
			 switch(mcSettings::m_etExportFormat)
			 {
			 case 0:
				 ext = "TIFF (*.tif) | *.tif";
				 break;
			 case 1:
				 ext = "PNG (*.png) | *.png";
				 break;
			 case 2:
				 ext = "BMP (*.bmp) | *.bmp";
				 break;
			 }
			 return ext;
		 }
private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_aoFFTWindowType = listBox2->SelectedIndex;
			 mcSample::GenFFTWindow();
		 }

private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ Save2DTRSFile = gcnew SaveFileDialog();
			 Save2DTRSFile->Title = L"Save TRS";
			 Save2DTRSFile->Filter = "DAT (*.dat)|*.dat";
			 if (Save2DTRSFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 mcSample::SaveTRSToTextFile(Save2DTRSFile->FileName);
			 }
		 }
private: System::Void listBox7_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_mmdProjType = listBox7->SelectedIndex;
			 numericUpDown8->Value = 0;
			 switch(listBox7->SelectedIndex)
			 {
			 case 0:
				 label81->Text = L"Z:";
				 label83->Text = L"Z:";
				 //numericUpDown8->Maximum = cDataContainer::SimulationsData.s_params.m_SizeZ - 1;
				 numericUpDown8->Maximum = cProbe::sizeZ - 1;
				 break;
			 case 1:
				 label81->Text = L"Y:";
				 label83->Text = L"Y:";
				 //numericUpDown8->Maximum = cDataContainer::SimulationsData.s_params.m_SizeY - 1;
				 numericUpDown8->Maximum = cProbe::sizeY - 1;
				 break;
			 case 2:
				 label81->Text = L"X:";
				 label83->Text = L"X:";
				 //numericUpDown8->Maximum = cDataContainer::SimulationsData.s_params.m_SizeX - 1;
				 numericUpDown8->Maximum = cProbe::sizeX - 1;
				 break;
			 }
		 }
private: System::Void listBox8_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_mmdMode = listBox8->SelectedIndex;
		 }
private: System::Void listBox9_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_mmdBSMode = listBox9->SelectedIndex;
		 }
private: System::Void numericUpDown7_ValueChanged(System::Object^  sender, System::EventArgs^  e) {	
			 mcSettings::m_mmdStepi = Convert::ToInt32(numericUpDown7->Value);
			 float step = cDataContainer::SimulationsData.s_params.m_StageTime;
			 if (cDataContainer::SimulationsData.m_IsFreqDomain) step = cDataContainer::SimulationsData.s_params.m_ResFrequency;
			 float freq = Convert::ToSingle(mcSettings::m_mmdStepi) * step;
			 mcSettings::m_mmdStepf = freq;
			 maskedTextBox26->Text = Convert::ToString(freq);
			 drawmode();

		 }
private: System::Void numericUpDown8_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_mmdDepthi = Convert::ToInt32(numericUpDown8->Value);
			 float mult = 1.0;
			 switch(mcSettings::m_mmdProjType)
			 {
			 case 0:
				 mult = cDataContainer::SimulationsData.s_params.m_CellSizeZ;
				 if (cDataContainer::SimulationsData.m_IsKDomain) mult = cProbe::m_multResInverseWavelengthZ * cDataContainer::SimulationsData.s_params.m_ResInverseWavelengthZ;
				 break;
			 case 1:
				 mult = cDataContainer::SimulationsData.s_params.m_CellSizeY;
				 if (cDataContainer::SimulationsData.m_IsKDomain) mult = cProbe::m_multResInverseWavelengthY * cDataContainer::SimulationsData.s_params.m_ResInverseWavelengthY;
				 break;
			 case 2:
				 mult = cDataContainer::SimulationsData.s_params.m_CellSizeX;
				 if (cDataContainer::SimulationsData.m_IsKDomain) mult = cProbe::m_multResInverseWavelengthX * cDataContainer::SimulationsData.s_params.m_ResInverseWavelengthX;
				 break;
			 }
			 float depth = 0.0F;
			 if (cDataContainer::SimulationsData.m_IsKDomain) depth = mult * Convert::ToSingle(mcSettings::m_mmdDepthi);
			 else
			 {
				 switch(mcSettings::m_mmdProjType)
				 {
				 case 0:
					 depth = mult * Convert::ToSingle(cProbe::Z0 + mcSettings::m_mmdDepthi);
					 break;
				 case 1:
					 depth = mult * Convert::ToSingle(cProbe::Y0 + mcSettings::m_mmdDepthi);
					 break;
				 case 2:
					 depth = mult * Convert::ToSingle(cProbe::X0 + mcSettings::m_mmdDepthi);
					 break;
				 }
			 }
			 mcSettings::m_mmdDepthf = depth;
			 maskedTextBox27->Text = Convert::ToString(depth);
			 drawmode();

		 }
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
			 drawmode();

			 if (cDataContainer::SimulationsData.m_IsFreqDomain && !(cDataContainer::SimulationsData.m_IsKDomain) && cDataContainer::p_ExtractingMethod.m_MagnetizationComponent == 4)
			 {
				 // get multipole coefficients
				 System::String^ mulcoeff = gcnew System::String("");
				 mcSample::GetMultipoleExpansion(mulcoeff);	
				 richTextBox2->Text = mulcoeff;

			 }
		 }
private: System::Void drawmode()
		 {
			 if (cDataContainer::SimulationsData.m_IsLoaded != 0 )
			 {
				 switch(mcSettings::m_mmdProjType)
				 {
				 case 0:
					 // XY
					 label69->Text = L"XY";
					 label73->Text = L"X";
					 label75->Text = L"Y";
					 label68->Text = L"XY";
					 label72->Text = L"X";
					 label74->Text = L"Y";
					 break;
				 case 1:
					 // XZ
					 label69->Text = L"XZ";
					 label73->Text = L"X";
					 label75->Text = L"Z";
					 label68->Text = L"XZ";
					 label72->Text = L"X";
					 label74->Text = L"Z";
					 break;
				 case 2:
					 // YZ
					 label69->Text = L"YZ";
					 label73->Text = L"Y";
					 label75->Text = L"Z";
					 label68->Text = L"YZ";
					 label72->Text = L"Y";
					 label74->Text = L"Z";
					 break;
				 }
				 mcSample::DrawMagnetization();
				 pictureBox7->Image = mcSample::mag_re;
				 pictureBox6->Image = mcSample::mag_img;

				 // Get wave numbers and wave vectors
				 System::String^ wavenum = gcnew System::String("");
				 mcSample::GetModeWaveVectors(wavenum);
			     richTextBox3->Text = wavenum;
			 }
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ Save2DTRSFile = gcnew SaveFileDialog();
			 Save2DTRSFile->Title = L"Save FRS";
			 Save2DTRSFile->Filter = "DAT (*.dat)|*.dat";
			 if (Save2DTRSFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 mcSample::SaveFRSToTextFile(Save2DTRSFile->FileName);
			 }
		 }
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ name = gcnew System::String("");
			 System::String^ header = gcnew System::String("# SEMARGL3 OUTPUT:\n");
			 header += L"# 2D profile of magnetization of the given time/frequency and depth/wavevector\n";
			 this->GenerateTextForProfiles(name, header, 0);
			 header += "X Y VALUE";
			 this->SaveImageToFile(mcSample::mag_re, name);
		 }
private: System::Void GenerateTextForProfiles(System::String^% name, System::String^% header, long long graph)
		 {
			 header += "# PLANE:\t";
			 switch(mcSettings::m_mmdProjType)
			 {
			 case 0:
				 name += L"XY-";
				 header += L"XY\n";
				 break;
			 case 1:
				 name += L"XZ-";
				 header += L"XZ\n";
				 break;
			 case 2:
				 name += L"YZ-";
				 header += L"YZ\n";
				 break;
			 }
			 System::String^ component= gcnew System::String("M");
			 switch(cDataContainer::p_ExtractingMethod.m_MagnetizationComponent)
			 {
			 case 0:
				 component += L"x)";
				 break;
			 case 1:
				 component += L"y)";
				 break;
			 case 2:
				 component += L"z)";
				 break;
			 }
			 header += L"# COMPONENT:\t";
			 switch(graph)
			 {
			 case 0:
				 switch(mcSettings::m_mmdMode)
				 {
				 case 0:
					 name += L"Re(";
					 name += component;
					 name += "-";

					 header += "Re(";
					 header += component;
					 header += "\n";
					 break;
				 case 1:
					 name += L"Amp(";
					 name += component;
					 name += "-";

					 header += L"Amp(";
					 header += component;
					 header += "\n";
					 break;
				 }
				 break;
			 case 1:
				 switch(mcSettings::m_mmdMode)
				 {
				 case 0:
					 name += L"Img(";
					 name += component;
					 name += "-";

					 header += L"Img(";
					 header += component;
					 header += "\n";
					 break;
				 case 1:
					 name += L"Phs(";
					 name += component;
					 name += "-";

					 header += L"Phs(";
					 header += component;
					 header += "\n";
					 break;
				 }
				 break;
			 case 2:
				 switch(mcSettings::m_mmdMode)
				 {
				 case 0:
					 name += L"Re(";
					 name += component;
					 name += "-";

					 header += "Re(";
					 header += component;
					 header += " ";

					 name += L"Img(";
					 name += component;
					 name += "-";
					 
					 header += L"Img(";
					 header += component;
					 header += "\n";
					 break;
				 case 1:
					 name += L"Amp(";
					 name += component;
					 name += "-";

					 header += "Phase(";
					 header += component;
					 header += " ";

					 name += L"Amp(";
					 name += component;
					 name += "-";
					 
					 header += L"Phase(";
					 header += component;
					 header += "\n";
					 break;
				 }
				 break;

			 }
			 float time = 0.0F;
			 System::String^ stime;
			 float depth = 0.0F;
			 System::String^ sdepth;

			 switch(cDataContainer::SimulationsData.m_IsFreqDomain)
			 {
			 case 0:
				 time = mcSettings::m_mmdStepf;
				 stime = Convert::ToString(time);
				 name += "T";
				 name += stime;
				 name += "s-";
				 header += L"# TIME:\t";
				 header += stime;
				 header += " s\n";
				 break;
			 case 1:
				 float freq = mcSettings::m_mmdStepf * 1e-9; // Hz to GHZ
				 System::String^ sfreq = Convert::ToString(freq);
				 name += "F";
				 name += sfreq;
				 name += "GHz-";
				 header += L"# FREQUENCY:\t";
				 header += sfreq;
				 header += " GHz\n";
				 break;
			 }
			 switch(cDataContainer::SimulationsData.m_IsKDomain)
			 {
			 case 0:
				 depth = mcSettings::m_mmdDepthf;
				 sdepth = Convert::ToString(depth);
				 name += "D";
				 name += sdepth;
				 name += "m-";
				 header += L"# DEPTH:\t";
				 header += sdepth;
				 header += " s\n";
				 break;
			 case 1:
				 float K = mcSettings::m_mmdDepthf;
				 System::String^ sK = Convert::ToString(K);
				 name += "K";
				 name += sK;
				 name += "(m-1)-";
				 header += L"# WAVEVECTOR:\t";
				 header += sK;
				 header += " m^(-1)\n";
				 break;
			 }
		 }
private: System::Void GenerateTextForProfiles3D(System::String^% name, System::String^% header, long long graph)
		 {
			 
			 System::String^ component= gcnew System::String("M");
			 switch(cDataContainer::p_ExtractingMethod.m_MagnetizationComponent)
			 {
			 case 0:
				 component += L"x)";
				 break;
			 case 1:
				 component += L"y)";
				 break;
			 case 2:
				 component += L"z)";
				 break;
			 }
			 header += L"# COMPONENT:\t";
			 switch(graph)
			 {
			 case 0:
				 switch(mcSettings::m_mmdMode)
				 {
				 case 0:
					 name += L"Re(";
					 name += component;
					 name += "-";

					 header += "Re(";
					 header += component;
					 header += "\n";
					 break;
				 case 1:
					 name += L"Amp(";
					 name += component;
					 name += "-";

					 header += L"Amp(";
					 header += component;
					 header += "\n";
					 break;
				 }
				 break;
			 case 1:
				 switch(mcSettings::m_mmdMode)
				 {
				 case 0:
					 name += L"Img(";
					 name += component;
					 name += "-";

					 header += L"Img(";
					 header += component;
					 header += "\n";
					 break;
				 case 1:
					 name += L"Phs(";
					 name += component;
					 name += "-";

					 header += L"Phs(";
					 header += component;
					 header += "\n";
					 break;
				 }
				 break;
			 case 2:
				 switch(mcSettings::m_mmdMode)
				 {
				 case 0:
					 name += L"Re(";
					 name += component;
					 name += "-";

					 header += "Re(";
					 header += component;
					 header += " ";

					 name += L"Img(";
					 name += component;
					 name += "-";
					 
					 header += L"Img(";
					 header += component;
					 header += "\n";
					 break;
				 case 1:
					 name += L"Amp(";
					 name += component;
					 name += "-";

					 header += "Phase(";
					 header += component;
					 header += " ";

					 name += L"Amp(";
					 name += component;
					 name += "-";
					 
					 header += L"Phase(";
					 header += component;
					 header += "\n";
					 break;
				 }
				 break;

			 }
			 float time = 0.0F;
			 System::String^ stime;
			 float depth = 0.0F;
			 System::String^ sdepth;

			 switch(cDataContainer::SimulationsData.m_IsFreqDomain)
			 {
			 case 0:
				 time = mcSettings::m_mmdStepf;
				 stime = Convert::ToString(time);
				 name += "T";
				 name += stime;
				 name += "s-";
				 header += L"# TIME:\t";
				 header += stime;
				 header += " s\n";
				 break;
			 case 1:
				 float freq = mcSettings::m_mmdStepf * 1e-9; // Hz to GHZ
				 System::String^ sfreq = Convert::ToString(freq);
				 name += "F";
				 name += sfreq;
				 name += "GHz-";
				 header += L"# FREQUENCY:\t";
				 header += sfreq;
				 header += " GHz\n";
				 break;
			 }
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
				/*long long mode = 0;
				System::String^ name = gcnew System::String("");
				System::String^ header = gcnew System::String("# SEMARGL3 OUTPUT:\n");
				header += L"# 2D profile of magnetization of the given time/frequency and depth/wavevector\n";
				this->GenerateTextForProfiles(name, header, mode);
				header += "X Y VALUE";
				SaveFileDialog^ Save2DFile = gcnew SaveFileDialog();
				Save2DFile->Title = L"Save TRS";
				Save2DFile->FileName = name;
				Save2DFile->Filter = "DAT (*.dat)|*.dat";
				if (Save2DFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					mcSample::Save2DToTextFile(Save2DFile->FileName,
											header,
											mode);
				}*/

				System::String^ wavenum = gcnew System::String("");
				mcSample::GetModeWaveVectors(wavenum);

				mcSample::Get3DMode();
				long long mode = 0;
				System::String^ name = gcnew System::String("");
				System::String^ header = gcnew System::String("# SEMARGL3 OUTPUT:\n");
				header += L"# 3D profile of magnetization of the given time/frequency and depth/wavevector\n";
				header += wavenum;
				this->GenerateTextForProfiles3D(name, header, mode);
				header += "# X Y Z VALUE VALUE\n";
				SaveFileDialog^ Save2DFile = gcnew SaveFileDialog();
				Save2DFile->Title = L"Save mode profile";
				Save2DFile->FileName = name;
				Save2DFile->Filter = "DAT (*.dat)|*.dat";
				if (Save2DFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					mcSample::Save3DToTextFile(Save2DFile->FileName,
											header,
											mode);
				}
				mcSample::Delete3DMode();
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 long long mode = 1;
			 System::String^ name = gcnew System::String("");
			 System::String^ header = gcnew System::String("# SEMARGL3 OUTPUT:\n");
			 header += L"# 2D profile of magnetization of the given time/frequency and depth/wavevector\n";
			 this->GenerateTextForProfiles(name, header, mode);
			 header += "X Y VALUE";
			 SaveFileDialog^ Save2DFile = gcnew SaveFileDialog();
			 Save2DFile->Title = L"Save TRS";
			 Save2DFile->FileName = name;
			 Save2DFile->Filter = "DAT (*.dat)|*.dat";
			 if (Save2DFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 mcSample::Save2DToTextFile(Save2DFile->FileName,
											header,
											mode);
			 }
		 }
private: System::Void listBox11_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_fdaMethod = listBox11->SelectedIndex;
			 listBox13->Enabled = (mcSettings::m_fdaMethod == 0) ? true : false;
			 if (mcSettings::m_fdaMethod == 2)
			 {
				 listBox13->SelectedIndex = 1;
				 mcSettings::m_fdaAvgMethod = listBox13->SelectedIndex;
			 }
			 if (mcSettings::m_fdaMethod == 1)
			 {
				 listBox13->SelectedIndex = 0;
				 mcSettings::m_fdaAvgMethod = listBox13->SelectedIndex;
			 }

		 }
private: System::Void listBox12_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_fdaMode = listBox12->SelectedIndex;
		 }
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
			Thread^ do_spectrum = gcnew Thread(gcnew ThreadStart(&mcSample::DoSpectrum));
			do_spectrum->Start();
			this->toolStripProgressBar1->Value = 0;
			this->Enabled = false;
			while (do_spectrum->IsAlive)
			{
				toolStripProgressBar1->Value = (toolStripProgressBar1->Value + 5) & toolStripProgressBar1->Maximum;
				Thread::Sleep(100);
			}
			this->Enabled = true;	
		 }
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ name = gcnew System::String("");
			 SaveFileDialog^ Save2DFile = gcnew SaveFileDialog();
			 Save2DFile->Title = L"Save spectrum of the magnetization";
			 Save2DFile->FileName = name;
			 Save2DFile->Filter = "DAT (*.dat)|*.dat";
			 if (Save2DFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 mcSample::SaveSpectrumToTextFile(Save2DFile->FileName);
			 }
		 }
private: System::Void listBox13_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_fdaAvgMethod = listBox13->SelectedIndex;
		 }
private: System::Void listBox14_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_dcIsAvgX = listBox14->SelectedIndex;
		 }
private: System::Void listBox15_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_dcIsAvgY = listBox15->SelectedIndex;
		 }
private: System::Void listBox16_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_dcIsAvgZ = listBox16->SelectedIndex;
		 }
private: System::Void listBox19_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_dcAvgMethodX = listBox19->SelectedIndex;
		 }
private: System::Void listBox18_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_dcAvgMethodY = listBox18->SelectedIndex;
		 }
private: System::Void listBox17_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_dcAvgMethodZ = listBox17->SelectedIndex;
		 }
private: System::Void numericUpDown9_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 long long kx = Convert::ToInt32(numericUpDown9->Value);
			 double kx_mult = cProbe::m_multResInverseWavelengthX * cDataContainer::SimulationsData.s_params.m_ResInverseWavelengthX; // probe should be taken into account
			 float r_kx = Convert::ToSingle(kx_mult * Convert::ToDouble(kx)) - cDataContainer::SimulationsData.s_params.m_MaxInverseWavelengthX;

			 mcSettings::m_dcProbeXi = kx;
			 mcSettings::m_dcProbeXf = r_kx;

			 maskedTextBox28->Text = Convert::ToString(r_kx);
		 }
private: System::Void numericUpDown10_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 long long ky = Convert::ToInt32(numericUpDown10->Value);
			 double ky_mult = cProbe::m_multResInverseWavelengthY * cDataContainer::SimulationsData.s_params.m_ResInverseWavelengthY; // probe should be taken into account
			 float r_ky = Convert::ToSingle(ky_mult * Convert::ToDouble(ky)) - cDataContainer::SimulationsData.s_params.m_MaxInverseWavelengthY;

			 mcSettings::m_dcProbeYi = ky;
			 mcSettings::m_dcProbeYf = r_ky;

			 maskedTextBox29->Text = Convert::ToString(r_ky);
		 }
private: System::Void numericUpDown11_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 long long kz = Convert::ToInt32(numericUpDown11->Value);
			 double kz_mult = cProbe::m_multResInverseWavelengthZ * cDataContainer::SimulationsData.s_params.m_ResInverseWavelengthZ; // probe should be taken into account
			 float r_kz = Convert::ToSingle(kz_mult * Convert::ToDouble(kz)) - cDataContainer::SimulationsData.s_params.m_MaxInverseWavelengthZ;

			 mcSettings::m_dcProbeZi = kz;
			 mcSettings::m_dcProbeZf = r_kz;

			 maskedTextBox30->Text = Convert::ToString(r_kz);
		 }
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
			/*Thread^ do_dispersion = gcnew Thread(gcnew ThreadStart(&mcSample::Do3DDispersion));
			do_dispersion->Start();
			this->toolStripProgressBar1->Value = 0;
			this->Enabled = false;
			while (do_dispersion->IsAlive)
			{
				toolStripProgressBar1->Value = (toolStripProgressBar1->Value + 5) & toolStripProgressBar1->Maximum;
				Thread::Sleep(100);
			}
			this->Enabled = true;
			 button18->Enabled = false;
			 groupBox19->Enabled = true; */
		 }
private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {

			Thread^ do_dispersion = gcnew Thread(gcnew ThreadStart(&mcSample::GetSliceOf3DDispersion));

			Stopwatch^ timer = Stopwatch::StartNew();
			do_dispersion->Start();
			this->toolStripProgressBar1->Value = 0;
			this->Enabled = false;
			while (do_dispersion->IsAlive)
			{
				toolStripProgressBar1->Value = (toolStripProgressBar1->Value + 5) & toolStripProgressBar1->Maximum;
				Thread::Sleep(100);
			}
			timer->Stop();
			Int64 timeHP = timer->ElapsedTicks/timer->Frequency;
			label108->Text = Convert::ToString(timeHP)+" s";

			this->Enabled = true;
			button18->Enabled = false; 

			 //mcSample::GetSliceOf3DDispersion();			 
		 }
private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
				DrawDispersion();
			  //mcSample::DrawDispersionSlice();
			  //pictureBox9->Image = mcSample::dispersion;
		 }
private: System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->SaveImageToFile(mcSample::dispersion, L"");
		 }
private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ name = gcnew System::String("");
			 SaveFileDialog^ Save2DFile = gcnew SaveFileDialog();
			 Save2DFile->Title = L"Save spectrum of the magnetization";
			 Save2DFile->FileName = name;
			 Save2DFile->Filter = "DAT (*.dat)|*.dat";
			 if (Save2DFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 mcSample::SaveDispersionToTextFile(Save2DFile->FileName);
			 }
		 }
private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_dcImageBr = trackBar1->Value;
			 label1->Text = Convert::ToString(mcSettings::m_dcImageBr);
			 mcSample::DrawDispersionSlice();
			 pictureBox9->Image = mcSample::dispersion;
			 pictureBox9->Refresh();
		 }
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ name = gcnew System::String("");
			 System::String^ header = gcnew System::String("# SEMARGL3 OUTPUT:\n");
			 header += L"# 2D profile of magnetization of the given time/frequency and depth/wavevector\n";
			 this->GenerateTextForProfiles(name, header, 1);
			 header += "X Y VALUE";
			 this->SaveImageToFile(mcSample::mag_img, name);
		 }
private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_trTRSImageBr = trackBar2->Value;
			 label105->Text = Convert::ToString(mcSettings::m_trTRSImageBr);
			 mcImage::Draw2DTRS();
			 pictureBox2->Image = mcSample::trs_image;
			 pictureBox2->Refresh();
		 }

private: System::Void tabPage2_Leave(System::Object^  sender, System::EventArgs^  e) {
			 gen_probe();
			 calcpart_on();
			 DrawProbe();
		 }
private: System::Void calcpart_off()
		 {
			 tabPage3->Enabled = false;
			 tabPage4->Enabled = false;
			 tabPage5->Enabled = false;

		 }
private: System::Void calcpart_on()
		 {
			 tabPage3->Enabled = true;
			 tabPage4->Enabled = true;
			 tabPage5->Enabled = true;
		 }
private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 Process::Start("mailto:mad211@ex.ac.uk");
		 }
private: System::Void listBox21_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_dcColorScale = listBox21->SelectedIndex;
			 DrawDispersion();
		 }
private: System::Void DrawDispersion()
		 {
			 if (cDataContainer::SimulationsData.m_IsKDomain && cDataContainer::SimulationsData.m_IsFreqDomain && cDataContainer::SimulationsData.m_IsLoaded)
			 {
				mcSample::DrawDispersionSlice();
				pictureBox9->Image = mcSample::dispersion;
			 }
		 }
private: System::Void tabPage8_Enter(System::Object^  sender, System::EventArgs^  e) {
			if (cDataContainer::SimulationsData.m_IsFreqDomain == 1)
			{
				label76->Text = L"Frequency:";
				label78->Text = L"Frequency:";
				label79->Text = L"Hz";
			}
			else 
			{
				label76->Text = L"Time step:";
				label78->Text = L"Time Step:";
				label79->Text = L"s";
			}
			groupBox26->Enabled = (cDataContainer::SimulationsData.m_IsFreqDomain && !(cDataContainer::SimulationsData.m_IsKDomain) && cDataContainer::p_ExtractingMethod.m_MagnetizationComponent == 4)?true:false;
		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 toolStripButton2->Enabled = !(checkBox2->Checked);
		 }
private: System::Void numericUpDown14_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 double skindepthX = Convert::ToDouble(numericUpDown14->Value) * cDataContainer::SimulationsData.s_params.m_CellSizeX;
			 cProbe::m_skindepthX = skindepthX;
			 maskedTextBox33->Text = Convert::ToString(skindepthX);
			 mcImage::DrawProbe();
			 switch(mcSettings::m_prViewPortProj)
			 {
			 case 0:
				 pictureBox1->Image = mcSample::sample_xy;
				 break;
			 case 1:
				 pictureBox1->Image = mcSample::sample_xz;
				 break;
			 case 2:
				 pictureBox1->Image = mcSample::sample_yz;
				 break;
			 }
		 }
private: System::Void numericUpDown13_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 double skindepthY = Convert::ToDouble(numericUpDown13->Value) * cDataContainer::SimulationsData.s_params.m_CellSizeY;
			 cProbe::m_skindepthY = skindepthY;
			 maskedTextBox32->Text = Convert::ToString(skindepthY);
			 mcImage::DrawProbe();
			 switch(mcSettings::m_prViewPortProj)
			 {
			 case 0:
				 pictureBox1->Image = mcSample::sample_xy;
				 break;
			 case 1:
				 pictureBox1->Image = mcSample::sample_xz;
				 break;
			 case 2:
				 pictureBox1->Image = mcSample::sample_yz;
				 break;
			 }
		 }
private: System::Void numericUpDown12_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 double skindepthZ = Convert::ToDouble(numericUpDown12->Value) * cDataContainer::SimulationsData.s_params.m_CellSizeZ;
			 cProbe::m_skindepthZ = skindepthZ;
			 maskedTextBox31->Text = Convert::ToString(skindepthZ);
			 mcImage::DrawProbe();
			 switch(mcSettings::m_prViewPortProj)
			 {
			 case 0:
				 pictureBox1->Image = mcSample::sample_xy;
				 break;
			 case 1:
				 pictureBox1->Image = mcSample::sample_xz;
				 break;
			 case 2:
				 pictureBox1->Image = mcSample::sample_yz;
				 break;
			 }
		 }
private: System::Void radioButton10_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton10->Checked) cDataContainer::p_ExtractingMethod.m_MagnetizationComponent = 4;
		 }
private: System::Void label130_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void listBox22_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 
			 mcSettings::m_trFRSMode = listBox22->SelectedIndex;
			 DrawFRS();
		 }
private: System::Void trackBar3_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 mcSettings::m_trFRSImageBr = trackBar3->Value;
			 label107->Text = Convert::ToString(mcSettings::m_trFRSImageBr);
			 DrawFRS();
		 }
private: System::Void DrawFRS()
		 {
			 if (cDataContainer::SimulationsData.m_IsLoaded) mcImage::Draw2DFRS();
			 pictureBox3->Image = mcSample::frs_image;
		 }
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
			 // batch save of the modes profiles
			 if (cDataContainer::SimulationsData.m_IsLoaded)
			 {
				mcSample::SaveProfilesBatch();
			 }
		 }
private: System::Void toolStripButton4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void Clean()
		 {
			 CleanPictureBoxes();
			 cDataContainer::Clean();
		 }

private: System::Void CleanPictureBoxes()
		 {
			 pictureBox1->Image->~Image();
			 pictureBox2->Image->~Image();
			 pictureBox3->Image->~Image();
			 pictureBox4->Image->~Image();
			 pictureBox5->Image->~Image();
			 pictureBox6->Image->~Image();
			 pictureBox7->Image->~Image();
			 pictureBox8->Image->~Image();
			 pictureBox9->Image->~Image();
			 mcSample::Clean();
		 }
};
}
