#pragma once

namespace p1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bLoadFile;
	protected:


	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TrackBar^  tbThreshold;
	private: System::Windows::Forms::CheckBox^  cbCapture;
	private: System::Windows::Forms::TrackBar^  tbThreshold2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;








	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button_speed;

	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label_xneg;
	private: System::Windows::Forms::Label^  label_xpos;
	private: System::Windows::Forms::Label^  label_yneg;
	private: System::Windows::Forms::Label^  label_ypos;




	private: System::Windows::Forms::Label^  Pick;


	private: System::Windows::Forms::Label^  Vac1;
	private: System::Windows::Forms::Label^  Vac2;
	private: System::Windows::Forms::Label^  Blow1;
	private: System::Windows::Forms::Label^  Blow2;
	private: System::Windows::Forms::Label^  Pres1;
	private: System::Windows::Forms::Label^  Pres2;
	private: System::Windows::Forms::Label^  Strip;
	private: System::Windows::Forms::Button^  button_pump;
	private: System::Windows::Forms::Button^  button_strip;
	private: System::Windows::Forms::Button^  button_pick;
	private: System::Windows::Forms::Button^  button_vac1;
	private: System::Windows::Forms::Button^  button_vac2;
	private: System::Windows::Forms::Button^  button_blow1;
	private: System::Windows::Forms::Button^  button_blow2;
	private: System::Windows::Forms::Button^  button_a1_pos;
	private: System::Windows::Forms::Button^  button_a1_neg;
	private: System::Windows::Forms::Button^  button_a2_pos;
	private: System::Windows::Forms::Button^  button_a2_neg;
	private: System::Windows::Forms::Button^  button_n1up;
	private: System::Windows::Forms::Button^  button_n1dw;
	private: System::Windows::Forms::Button^  button_n2up;
	private: System::Windows::Forms::Button^  button_n2dw;
	private: System::Windows::Forms::Button^  button_ypos;
	private: System::Windows::Forms::Button^  button_yneg;
	private: System::Windows::Forms::Button^  button_xneg;
	private: System::Windows::Forms::Button^  button_xpos;
	private: System::Windows::Forms::Button^  Run;
	private: System::Windows::Forms::Button^  Step;
	private: System::Windows::Forms::Button^  Pause;
	private: System::Windows::Forms::Label^  X_coord;
	private: System::Windows::Forms::Label^  Y_coord;
	private: System::Windows::Forms::Label^  A1_rot;
	private: System::Windows::Forms::Label^  A2_rot;
	private: System::Windows::Forms::Label^  Z1;
	private: System::Windows::Forms::Label^  Z2;
	private: System::Windows::Forms::Label^  Status;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  c1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  c8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  c3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  c2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  c4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  c5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  c6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  c7;
	private: System::Windows::Forms::TrackBar^  SpeedBar;
private: System::Windows::Forms::Label^  SpeedLabel;
private: System::Windows::Forms::Button^  button_home;
private: System::Windows::Forms::TrackBar^  AccelBar;
private: System::Windows::Forms::TrackBar^  DescelBar;
private: System::Windows::Forms::Label^  AccelLabel;
private: System::Windows::Forms::Label^  DescelLabel;
private: System::Windows::Forms::Button^  button_Manual;
private: System::Windows::Forms::Button^  button_Move;
private: System::Windows::Forms::TextBox^  X_box;
private: System::Windows::Forms::TextBox^  Y_box;
private: System::Windows::Forms::Label^  X_label;
private: System::Windows::Forms::Label^  Y_label;
private: System::Windows::Forms::Button^  X_go;
private: System::Windows::Forms::Button^  Y_go;
private: System::Windows::Forms::Button^  X_stop;
private: System::Windows::Forms::Button^  Y_stop;
private: System::Windows::Forms::OpenFileDialog^  Browse_File;















































































	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->bLoadFile = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tbThreshold = (gcnew System::Windows::Forms::TrackBar());
			this->cbCapture = (gcnew System::Windows::Forms::CheckBox());
			this->tbThreshold2 = (gcnew System::Windows::Forms::TrackBar());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->c1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button_speed = (gcnew System::Windows::Forms::Button());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label_xneg = (gcnew System::Windows::Forms::Label());
			this->label_xpos = (gcnew System::Windows::Forms::Label());
			this->label_yneg = (gcnew System::Windows::Forms::Label());
			this->label_ypos = (gcnew System::Windows::Forms::Label());
			this->Pick = (gcnew System::Windows::Forms::Label());
			this->Vac1 = (gcnew System::Windows::Forms::Label());
			this->Vac2 = (gcnew System::Windows::Forms::Label());
			this->Blow1 = (gcnew System::Windows::Forms::Label());
			this->Blow2 = (gcnew System::Windows::Forms::Label());
			this->Pres1 = (gcnew System::Windows::Forms::Label());
			this->Pres2 = (gcnew System::Windows::Forms::Label());
			this->Strip = (gcnew System::Windows::Forms::Label());
			this->button_pump = (gcnew System::Windows::Forms::Button());
			this->button_strip = (gcnew System::Windows::Forms::Button());
			this->button_pick = (gcnew System::Windows::Forms::Button());
			this->button_vac1 = (gcnew System::Windows::Forms::Button());
			this->button_vac2 = (gcnew System::Windows::Forms::Button());
			this->button_blow1 = (gcnew System::Windows::Forms::Button());
			this->button_blow2 = (gcnew System::Windows::Forms::Button());
			this->button_a1_pos = (gcnew System::Windows::Forms::Button());
			this->button_a1_neg = (gcnew System::Windows::Forms::Button());
			this->button_a2_pos = (gcnew System::Windows::Forms::Button());
			this->button_a2_neg = (gcnew System::Windows::Forms::Button());
			this->button_n1up = (gcnew System::Windows::Forms::Button());
			this->button_n1dw = (gcnew System::Windows::Forms::Button());
			this->button_n2up = (gcnew System::Windows::Forms::Button());
			this->button_n2dw = (gcnew System::Windows::Forms::Button());
			this->button_ypos = (gcnew System::Windows::Forms::Button());
			this->button_yneg = (gcnew System::Windows::Forms::Button());
			this->button_xneg = (gcnew System::Windows::Forms::Button());
			this->button_xpos = (gcnew System::Windows::Forms::Button());
			this->Run = (gcnew System::Windows::Forms::Button());
			this->Step = (gcnew System::Windows::Forms::Button());
			this->Pause = (gcnew System::Windows::Forms::Button());
			this->X_coord = (gcnew System::Windows::Forms::Label());
			this->Y_coord = (gcnew System::Windows::Forms::Label());
			this->A1_rot = (gcnew System::Windows::Forms::Label());
			this->A2_rot = (gcnew System::Windows::Forms::Label());
			this->Z1 = (gcnew System::Windows::Forms::Label());
			this->Z2 = (gcnew System::Windows::Forms::Label());
			this->Status = (gcnew System::Windows::Forms::Label());
			this->SpeedBar = (gcnew System::Windows::Forms::TrackBar());
			this->SpeedLabel = (gcnew System::Windows::Forms::Label());
			this->button_home = (gcnew System::Windows::Forms::Button());
			this->AccelBar = (gcnew System::Windows::Forms::TrackBar());
			this->DescelBar = (gcnew System::Windows::Forms::TrackBar());
			this->AccelLabel = (gcnew System::Windows::Forms::Label());
			this->DescelLabel = (gcnew System::Windows::Forms::Label());
			this->button_Manual = (gcnew System::Windows::Forms::Button());
			this->button_Move = (gcnew System::Windows::Forms::Button());
			this->X_box = (gcnew System::Windows::Forms::TextBox());
			this->Y_box = (gcnew System::Windows::Forms::TextBox());
			this->X_label = (gcnew System::Windows::Forms::Label());
			this->Y_label = (gcnew System::Windows::Forms::Label());
			this->X_go = (gcnew System::Windows::Forms::Button());
			this->Y_go = (gcnew System::Windows::Forms::Button());
			this->X_stop = (gcnew System::Windows::Forms::Button());
			this->Y_stop = (gcnew System::Windows::Forms::Button());
			this->Browse_File = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbThreshold))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbThreshold2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SpeedBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccelBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DescelBar))->BeginInit();
			this->SuspendLayout();
			// 
			// bLoadFile
			// 
			this->bLoadFile->Location = System::Drawing::Point(12, 12);
			this->bLoadFile->Name = L"bLoadFile";
			this->bLoadFile->Size = System::Drawing::Size(119, 20);
			this->bLoadFile->TabIndex = 0;
			this->bLoadFile->Text = L"Load File";
			this->bLoadFile->UseVisualStyleBackColor = true;
			this->bLoadFile->Click += gcnew System::EventHandler(this, &MyForm::bLoadFile_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// tbThreshold
			// 
			this->tbThreshold->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbThreshold->Location = System::Drawing::Point(622, 15);
			this->tbThreshold->Maximum = 100;
			this->tbThreshold->Name = L"tbThreshold";
			this->tbThreshold->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->tbThreshold->Size = System::Drawing::Size(45, 205);
			this->tbThreshold->TabIndex = 2;
			this->tbThreshold->Value = 50;
			// 
			// cbCapture
			// 
			this->cbCapture->AutoSize = true;
			this->cbCapture->Checked = true;
			this->cbCapture->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbCapture->Location = System::Drawing::Point(536, 15);
			this->cbCapture->Name = L"cbCapture";
			this->cbCapture->Size = System::Drawing::Size(75, 17);
			this->cbCapture->TabIndex = 3;
			this->cbCapture->Text = L"cbCapture";
			this->cbCapture->UseVisualStyleBackColor = true;
			// 
			// tbThreshold2
			// 
			this->tbThreshold2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbThreshold2->Location = System::Drawing::Point(673, 12);
			this->tbThreshold2->Maximum = 400;
			this->tbThreshold2->Name = L"tbThreshold2";
			this->tbThreshold2->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->tbThreshold2->Size = System::Drawing::Size(45, 208);
			this->tbThreshold2->TabIndex = 4;
			this->tbThreshold2->Value = 50;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->c1, this->c8,
					this->c3, this->c2, this->c4, this->c5, this->c6, this->c7
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 40);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(599, 432);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// c1
			// 
			this->c1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->c1->HeaderText = L"Component ID";
			this->c1->Name = L"c1";
			// 
			// c8
			// 
			this->c8->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->c8->FillWeight = 80;
			this->c8->HeaderText = L"Value";
			this->c8->Name = L"c8";
			// 
			// c3
			// 
			this->c3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->c3->FillWeight = 80;
			this->c3->HeaderText = L"Source";
			this->c3->Name = L"c3";
			// 
			// c2
			// 
			this->c2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->c2->HeaderText = L"Size";
			this->c2->Name = L"c2";
			this->c2->Width = 52;
			// 
			// c4
			// 
			this->c4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->c4->HeaderText = L"X";
			this->c4->Name = L"c4";
			this->c4->Width = 39;
			// 
			// c5
			// 
			this->c5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->c5->HeaderText = L"Y";
			this->c5->Name = L"c5";
			this->c5->Width = 39;
			// 
			// c6
			// 
			this->c6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->c6->HeaderText = L"Rotation";
			this->c6->Name = L"c6";
			this->c6->Width = 72;
			// 
			// c7
			// 
			this->c7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->c7->HeaderText = L"Height";
			this->c7->Name = L"c7";
			this->c7->Width = 63;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(137, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 20);
			this->button1->TabIndex = 6;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_click);
			// 
			// button_speed
			// 
			this->button_speed->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_speed->Location = System::Drawing::Point(739, 390);
			this->button_speed->Name = L"button_speed";
			this->button_speed->Size = System::Drawing::Size(99, 23);
			this->button_speed->TabIndex = 7;
			this->button_speed->Text = L"Cont/Step";
			this->button_speed->UseVisualStyleBackColor = true;
			this->button_speed->Click += gcnew System::EventHandler(this, &MyForm::button_speed_click);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 10;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_tick);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 496);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 25);
			this->label1->TabIndex = 8;
			this->label1->Text = L"label1";
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(388, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"label2";
			// 
			// label_xneg
			// 
			this->label_xneg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label_xneg->AutoSize = true;
			this->label_xneg->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_xneg->Location = System::Drawing::Point(851, 252);
			this->label_xneg->Name = L"label_xneg";
			this->label_xneg->Size = System::Drawing::Size(43, 15);
			this->label_xneg->TabIndex = 10;
			this->label_xneg->Text = L"X - LIM";
			// 
			// label_xpos
			// 
			this->label_xpos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label_xpos->AutoSize = true;
			this->label_xpos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_xpos->Location = System::Drawing::Point(898, 252);
			this->label_xpos->Name = L"label_xpos";
			this->label_xpos->Size = System::Drawing::Size(46, 15);
			this->label_xpos->TabIndex = 11;
			this->label_xpos->Text = L"X + LIM";
			// 
			// label_yneg
			// 
			this->label_yneg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label_yneg->AutoSize = true;
			this->label_yneg->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_yneg->Location = System::Drawing::Point(852, 274);
			this->label_yneg->Name = L"label_yneg";
			this->label_yneg->Size = System::Drawing::Size(43, 15);
			this->label_yneg->TabIndex = 12;
			this->label_yneg->Text = L"Y - LIM";
			// 
			// label_ypos
			// 
			this->label_ypos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label_ypos->AutoSize = true;
			this->label_ypos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label_ypos->Location = System::Drawing::Point(899, 274);
			this->label_ypos->Name = L"label_ypos";
			this->label_ypos->Size = System::Drawing::Size(46, 15);
			this->label_ypos->TabIndex = 13;
			this->label_ypos->Text = L"Y + LIM";
			// 
			// Pick
			// 
			this->Pick->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Pick->AutoSize = true;
			this->Pick->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Pick->Location = System::Drawing::Point(817, 252);
			this->Pick->Name = L"Pick";
			this->Pick->Size = System::Drawing::Size(30, 15);
			this->Pick->TabIndex = 14;
			this->Pick->Text = L"Pick";
			// 
			// Vac1
			// 
			this->Vac1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Vac1->AutoSize = true;
			this->Vac1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Vac1->Location = System::Drawing::Point(635, 252);
			this->Vac1->Name = L"Vac1";
			this->Vac1->Size = System::Drawing::Size(57, 15);
			this->Vac1->TabIndex = 15;
			this->Vac1->Text = L"Vacuum 1";
			// 
			// Vac2
			// 
			this->Vac2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Vac2->AutoSize = true;
			this->Vac2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Vac2->Location = System::Drawing::Point(634, 274);
			this->Vac2->Name = L"Vac2";
			this->Vac2->Size = System::Drawing::Size(57, 15);
			this->Vac2->TabIndex = 16;
			this->Vac2->Text = L"Vacuum 2";
			// 
			// Blow1
			// 
			this->Blow1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Blow1->AutoSize = true;
			this->Blow1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Blow1->Location = System::Drawing::Point(695, 252);
			this->Blow1->Name = L"Blow1";
			this->Blow1->Size = System::Drawing::Size(55, 15);
			this->Blow1->TabIndex = 17;
			this->Blow1->Text = L"Blowing 1";
			// 
			// Blow2
			// 
			this->Blow2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Blow2->AutoSize = true;
			this->Blow2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Blow2->Location = System::Drawing::Point(695, 274);
			this->Blow2->Name = L"Blow2";
			this->Blow2->Size = System::Drawing::Size(55, 15);
			this->Blow2->TabIndex = 18;
			this->Blow2->Text = L"Blowing 2";
			// 
			// Pres1
			// 
			this->Pres1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Pres1->AutoSize = true;
			this->Pres1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Pres1->Location = System::Drawing::Point(754, 252);
			this->Pres1->Name = L"Pres1";
			this->Pres1->Size = System::Drawing::Size(59, 15);
			this->Pres1->TabIndex = 19;
			this->Pres1->Text = L"Pressure 1";
			// 
			// Pres2
			// 
			this->Pres2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Pres2->AutoSize = true;
			this->Pres2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Pres2->Location = System::Drawing::Point(754, 274);
			this->Pres2->Name = L"Pres2";
			this->Pres2->Size = System::Drawing::Size(59, 15);
			this->Pres2->TabIndex = 20;
			this->Pres2->Text = L"Pressure 2";
			// 
			// Strip
			// 
			this->Strip->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Strip->AutoSize = true;
			this->Strip->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Strip->Location = System::Drawing::Point(818, 274);
			this->Strip->Name = L"Strip";
			this->Strip->Size = System::Drawing::Size(30, 15);
			this->Strip->TabIndex = 21;
			this->Strip->Text = L"Strip";
			// 
			// button_pump
			// 
			this->button_pump->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_pump->Location = System::Drawing::Point(629, 301);
			this->button_pump->Name = L"button_pump";
			this->button_pump->Size = System::Drawing::Size(104, 23);
			this->button_pump->TabIndex = 22;
			this->button_pump->Text = L"Pump";
			this->button_pump->UseVisualStyleBackColor = true;
			this->button_pump->Click += gcnew System::EventHandler(this, &MyForm::Pump_click);
			// 
			// button_strip
			// 
			this->button_strip->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_strip->Location = System::Drawing::Point(739, 301);
			this->button_strip->Name = L"button_strip";
			this->button_strip->Size = System::Drawing::Size(94, 23);
			this->button_strip->TabIndex = 23;
			this->button_strip->Text = L"Strip";
			this->button_strip->UseVisualStyleBackColor = true;
			this->button_strip->Click += gcnew System::EventHandler(this, &MyForm::Strip_press);
			// 
			// button_pick
			// 
			this->button_pick->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_pick->Location = System::Drawing::Point(839, 301);
			this->button_pick->Name = L"button_pick";
			this->button_pick->Size = System::Drawing::Size(109, 23);
			this->button_pick->TabIndex = 24;
			this->button_pick->Text = L"Pick";
			this->button_pick->UseVisualStyleBackColor = true;
			this->button_pick->Click += gcnew System::EventHandler(this, &MyForm::Pick_click);
			// 
			// button_vac1
			// 
			this->button_vac1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_vac1->Location = System::Drawing::Point(629, 331);
			this->button_vac1->Name = L"button_vac1";
			this->button_vac1->Size = System::Drawing::Size(75, 23);
			this->button_vac1->TabIndex = 25;
			this->button_vac1->Text = L"Vacuum 1";
			this->button_vac1->UseVisualStyleBackColor = true;
			this->button_vac1->Click += gcnew System::EventHandler(this, &MyForm::Vac1_click);
			// 
			// button_vac2
			// 
			this->button_vac2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_vac2->Location = System::Drawing::Point(711, 331);
			this->button_vac2->Name = L"button_vac2";
			this->button_vac2->Size = System::Drawing::Size(75, 23);
			this->button_vac2->TabIndex = 26;
			this->button_vac2->Text = L"Vacuum 2";
			this->button_vac2->UseVisualStyleBackColor = true;
			this->button_vac2->Click += gcnew System::EventHandler(this, &MyForm::Vac2_click);
			// 
			// button_blow1
			// 
			this->button_blow1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_blow1->Location = System::Drawing::Point(792, 331);
			this->button_blow1->Name = L"button_blow1";
			this->button_blow1->Size = System::Drawing::Size(75, 23);
			this->button_blow1->TabIndex = 27;
			this->button_blow1->Text = L"Blow 1";
			this->button_blow1->UseVisualStyleBackColor = true;
			this->button_blow1->Click += gcnew System::EventHandler(this, &MyForm::Blow1_click);
			// 
			// button_blow2
			// 
			this->button_blow2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_blow2->Location = System::Drawing::Point(873, 331);
			this->button_blow2->Name = L"button_blow2";
			this->button_blow2->Size = System::Drawing::Size(75, 23);
			this->button_blow2->TabIndex = 28;
			this->button_blow2->Text = L"Blow 2";
			this->button_blow2->UseVisualStyleBackColor = true;
			this->button_blow2->Click += gcnew System::EventHandler(this, &MyForm::Blow2_click);
			// 
			// button_a1_pos
			// 
			this->button_a1_pos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_a1_pos->Location = System::Drawing::Point(629, 361);
			this->button_a1_pos->Name = L"button_a1_pos";
			this->button_a1_pos->Size = System::Drawing::Size(75, 23);
			this->button_a1_pos->TabIndex = 29;
			this->button_a1_pos->Text = L"A1 Rotate +";
			this->button_a1_pos->UseVisualStyleBackColor = true;
			this->button_a1_pos->Click += gcnew System::EventHandler(this, &MyForm::A1pos_click);
			this->button_a1_pos->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::A1pos_mouseDown);
			// 
			// button_a1_neg
			// 
			this->button_a1_neg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_a1_neg->Location = System::Drawing::Point(711, 360);
			this->button_a1_neg->Name = L"button_a1_neg";
			this->button_a1_neg->Size = System::Drawing::Size(75, 23);
			this->button_a1_neg->TabIndex = 30;
			this->button_a1_neg->Text = L"A1 Rotate -";
			this->button_a1_neg->UseVisualStyleBackColor = true;
			this->button_a1_neg->Click += gcnew System::EventHandler(this, &MyForm::A1neg_click);
			this->button_a1_neg->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::A1neg_mouseDown);
			// 
			// button_a2_pos
			// 
			this->button_a2_pos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_a2_pos->Location = System::Drawing::Point(792, 360);
			this->button_a2_pos->Name = L"button_a2_pos";
			this->button_a2_pos->Size = System::Drawing::Size(75, 23);
			this->button_a2_pos->TabIndex = 31;
			this->button_a2_pos->Text = L"A2 Rotate +";
			this->button_a2_pos->UseVisualStyleBackColor = true;
			this->button_a2_pos->Click += gcnew System::EventHandler(this, &MyForm::A2pos_click);
			this->button_a2_pos->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::A2pos_mouseDown);
			// 
			// button_a2_neg
			// 
			this->button_a2_neg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_a2_neg->Location = System::Drawing::Point(873, 360);
			this->button_a2_neg->Name = L"button_a2_neg";
			this->button_a2_neg->Size = System::Drawing::Size(75, 23);
			this->button_a2_neg->TabIndex = 32;
			this->button_a2_neg->Text = L"A2 Rotate -";
			this->button_a2_neg->UseVisualStyleBackColor = true;
			this->button_a2_neg->Click += gcnew System::EventHandler(this, &MyForm::A2neg_click);
			this->button_a2_neg->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::A2neg_mouseDown);
			// 
			// button_n1up
			// 
			this->button_n1up->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_n1up->Location = System::Drawing::Point(629, 390);
			this->button_n1up->Name = L"button_n1up";
			this->button_n1up->Size = System::Drawing::Size(104, 23);
			this->button_n1up->TabIndex = 33;
			this->button_n1up->Text = L"Nozzle 1 UP";
			this->button_n1up->UseVisualStyleBackColor = true;
			this->button_n1up->Click += gcnew System::EventHandler(this, &MyForm::N1_up_click);
			this->button_n1up->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::N1_up_mouseDown);
			// 
			// button_n1dw
			// 
			this->button_n1dw->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_n1dw->Location = System::Drawing::Point(629, 419);
			this->button_n1dw->Name = L"button_n1dw";
			this->button_n1dw->Size = System::Drawing::Size(104, 23);
			this->button_n1dw->TabIndex = 34;
			this->button_n1dw->Text = L"Nozzle 1 DOWN";
			this->button_n1dw->UseVisualStyleBackColor = true;
			this->button_n1dw->Click += gcnew System::EventHandler(this, &MyForm::N1_dwn_click);
			this->button_n1dw->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::N1_dwn_mouseDown);
			// 
			// button_n2up
			// 
			this->button_n2up->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_n2up->Location = System::Drawing::Point(844, 390);
			this->button_n2up->Name = L"button_n2up";
			this->button_n2up->Size = System::Drawing::Size(104, 23);
			this->button_n2up->TabIndex = 35;
			this->button_n2up->Text = L"Nozzle 2 UP";
			this->button_n2up->UseVisualStyleBackColor = true;
			this->button_n2up->Click += gcnew System::EventHandler(this, &MyForm::N2_up_click);
			this->button_n2up->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::N2_up_mouseDown);
			// 
			// button_n2dw
			// 
			this->button_n2dw->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_n2dw->Location = System::Drawing::Point(844, 419);
			this->button_n2dw->Name = L"button_n2dw";
			this->button_n2dw->Size = System::Drawing::Size(104, 23);
			this->button_n2dw->TabIndex = 36;
			this->button_n2dw->Text = L"Nozzle 2 DOWN";
			this->button_n2dw->UseVisualStyleBackColor = true;
			this->button_n2dw->Click += gcnew System::EventHandler(this, &MyForm::N2_dwn_click);
			this->button_n2dw->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::N2_dwn_mouseDown);
			// 
			// button_ypos
			// 
			this->button_ypos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_ypos->Location = System::Drawing::Point(739, 419);
			this->button_ypos->Name = L"button_ypos";
			this->button_ypos->Size = System::Drawing::Size(99, 23);
			this->button_ypos->TabIndex = 37;
			this->button_ypos->Text = L"Move Y +";
			this->button_ypos->UseVisualStyleBackColor = true;
			this->button_ypos->Click += gcnew System::EventHandler(this, &MyForm::Ypos_click);
			this->button_ypos->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Ypos_mouseDown);
			// 
			// button_yneg
			// 
			this->button_yneg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_yneg->Location = System::Drawing::Point(739, 447);
			this->button_yneg->Name = L"button_yneg";
			this->button_yneg->Size = System::Drawing::Size(99, 23);
			this->button_yneg->TabIndex = 38;
			this->button_yneg->Text = L"Move Y -";
			this->button_yneg->UseVisualStyleBackColor = true;
			this->button_yneg->Click += gcnew System::EventHandler(this, &MyForm::Yneg_click);
			this->button_yneg->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Yneg_mouseDown);
			// 
			// button_xneg
			// 
			this->button_xneg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_xneg->Location = System::Drawing::Point(629, 447);
			this->button_xneg->Name = L"button_xneg";
			this->button_xneg->Size = System::Drawing::Size(104, 23);
			this->button_xneg->TabIndex = 39;
			this->button_xneg->Text = L"Move X -";
			this->button_xneg->UseVisualStyleBackColor = true;
			this->button_xneg->Click += gcnew System::EventHandler(this, &MyForm::Xneg_click);
			this->button_xneg->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Xneg_mouseDown);
			// 
			// button_xpos
			// 
			this->button_xpos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_xpos->Location = System::Drawing::Point(844, 448);
			this->button_xpos->Name = L"button_xpos";
			this->button_xpos->Size = System::Drawing::Size(104, 23);
			this->button_xpos->TabIndex = 40;
			this->button_xpos->Text = L"Move X +";
			this->button_xpos->UseVisualStyleBackColor = true;
			this->button_xpos->Click += gcnew System::EventHandler(this, &MyForm::Xpos_click);
			this->button_xpos->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Xpos_mouseDown);
			// 
			// Run
			// 
			this->Run->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Run->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Run->Location = System::Drawing::Point(968, 301);
			this->Run->Name = L"Run";
			this->Run->Size = System::Drawing::Size(120, 53);
			this->Run->TabIndex = 41;
			this->Run->Text = L"Run";
			this->Run->UseVisualStyleBackColor = true;
			// 
			// Step
			// 
			this->Step->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Step->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Step->Location = System::Drawing::Point(968, 360);
			this->Step->Name = L"Step";
			this->Step->Size = System::Drawing::Size(120, 53);
			this->Step->TabIndex = 42;
			this->Step->Text = L"Step";
			this->Step->UseVisualStyleBackColor = true;
			// 
			// Pause
			// 
			this->Pause->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Pause->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pause->Location = System::Drawing::Point(968, 419);
			this->Pause->Name = L"Pause";
			this->Pause->Size = System::Drawing::Size(120, 53);
			this->Pause->TabIndex = 43;
			this->Pause->Text = L"Pause";
			this->Pause->UseVisualStyleBackColor = true;
			// 
			// X_coord
			// 
			this->X_coord->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->X_coord->AutoSize = true;
			this->X_coord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->X_coord->Location = System::Drawing::Point(967, 229);
			this->X_coord->Name = L"X_coord";
			this->X_coord->Size = System::Drawing::Size(63, 13);
			this->X_coord->TabIndex = 44;
			this->X_coord->Text = L"X:   00.00";
			// 
			// Y_coord
			// 
			this->Y_coord->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Y_coord->AutoSize = true;
			this->Y_coord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Y_coord->Location = System::Drawing::Point(1035, 229);
			this->Y_coord->Name = L"Y_coord";
			this->Y_coord->Size = System::Drawing::Size(63, 13);
			this->Y_coord->TabIndex = 45;
			this->Y_coord->Text = L"Y:   00.00";
			// 
			// A1_rot
			// 
			this->A1_rot->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->A1_rot->AutoSize = true;
			this->A1_rot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A1_rot->Location = System::Drawing::Point(968, 274);
			this->A1_rot->Name = L"A1_rot";
			this->A1_rot->Size = System::Drawing::Size(62, 13);
			this->A1_rot->TabIndex = 46;
			this->A1_rot->Text = L"A1: 00.00";
			// 
			// A2_rot
			// 
			this->A2_rot->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->A2_rot->AutoSize = true;
			this->A2_rot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A2_rot->Location = System::Drawing::Point(1036, 274);
			this->A2_rot->Name = L"A2_rot";
			this->A2_rot->Size = System::Drawing::Size(62, 13);
			this->A2_rot->TabIndex = 47;
			this->A2_rot->Text = L"A2: 00.00";
			// 
			// Z1
			// 
			this->Z1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Z1->AutoSize = true;
			this->Z1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Z1->Location = System::Drawing::Point(968, 252);
			this->Z1->Name = L"Z1";
			this->Z1->Size = System::Drawing::Size(62, 13);
			this->Z1->TabIndex = 48;
			this->Z1->Text = L"Z1: 00.00";
			// 
			// Z2
			// 
			this->Z2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Z2->AutoSize = true;
			this->Z2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Z2->Location = System::Drawing::Point(1036, 252);
			this->Z2->Name = L"Z2";
			this->Z2->Size = System::Drawing::Size(62, 13);
			this->Z2->TabIndex = 49;
			this->Z2->Text = L"Z2: 00.00";
			// 
			// Status
			// 
			this->Status->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Status->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Status->Location = System::Drawing::Point(634, 225);
			this->Status->Name = L"Status";
			this->Status->Size = System::Drawing::Size(310, 20);
			this->Status->TabIndex = 50;
			this->Status->Text = L"Stopped";
			this->Status->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SpeedBar
			// 
			this->SpeedBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->SpeedBar->Enabled = false;
			this->SpeedBar->LargeChange = 1;
			this->SpeedBar->Location = System::Drawing::Point(629, 301);
			this->SpeedBar->Maximum = 100;
			this->SpeedBar->Name = L"SpeedBar";
			this->SpeedBar->Size = System::Drawing::Size(319, 45);
			this->SpeedBar->TabIndex = 51;
			this->SpeedBar->Value = 30;
			this->SpeedBar->Visible = false;
			this->SpeedBar->ValueChanged += gcnew System::EventHandler(this, &MyForm::SpeedChange);
			// 
			// SpeedLabel
			// 
			this->SpeedLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->SpeedLabel->AutoSize = true;
			this->SpeedLabel->Location = System::Drawing::Point(766, 336);
			this->SpeedLabel->Name = L"SpeedLabel";
			this->SpeedLabel->Size = System::Drawing::Size(64, 13);
			this->SpeedLabel->TabIndex = 58;
			this->SpeedLabel->Text = L"Speed: 30%";
			this->SpeedLabel->Visible = false;
			// 
			// button_home
			// 
			this->button_home->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_home->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_home->Location = System::Drawing::Point(739, 15);
			this->button_home->Name = L"button_home";
			this->button_home->Size = System::Drawing::Size(120, 46);
			this->button_home->TabIndex = 53;
			this->button_home->Text = L"Home";
			this->button_home->UseVisualStyleBackColor = true;
			this->button_home->Click += gcnew System::EventHandler(this, &MyForm::Home_click);
			// 
			// AccelBar
			// 
			this->AccelBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->AccelBar->Enabled = false;
			this->AccelBar->LargeChange = 1;
			this->AccelBar->Location = System::Drawing::Point(629, 338);
			this->AccelBar->Maximum = 100;
			this->AccelBar->Name = L"AccelBar";
			this->AccelBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->AccelBar->Size = System::Drawing::Size(45, 132);
			this->AccelBar->TabIndex = 54;
			this->AccelBar->Value = 30;
			this->AccelBar->Visible = false;
			this->AccelBar->ValueChanged += gcnew System::EventHandler(this, &MyForm::AccelChange);
			// 
			// DescelBar
			// 
			this->DescelBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->DescelBar->Enabled = false;
			this->DescelBar->LargeChange = 1;
			this->DescelBar->Location = System::Drawing::Point(917, 338);
			this->DescelBar->Maximum = 100;
			this->DescelBar->Name = L"DescelBar";
			this->DescelBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->DescelBar->Size = System::Drawing::Size(45, 132);
			this->DescelBar->TabIndex = 55;
			this->DescelBar->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->DescelBar->Value = 30;
			this->DescelBar->Visible = false;
			this->DescelBar->ValueChanged += gcnew System::EventHandler(this, &MyForm::DescelChange);
			// 
			// AccelLabel
			// 
			this->AccelLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->AccelLabel->AutoSize = true;
			this->AccelLabel->Location = System::Drawing::Point(672, 336);
			this->AccelLabel->Name = L"AccelLabel";
			this->AccelLabel->Size = System::Drawing::Size(92, 13);
			this->AccelLabel->TabIndex = 56;
			this->AccelLabel->Text = L"Acceleration: 30%";
			this->AccelLabel->Visible = false;
			// 
			// DescelLabel
			// 
			this->DescelLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->DescelLabel->AutoSize = true;
			this->DescelLabel->Location = System::Drawing::Point(836, 336);
			this->DescelLabel->Name = L"DescelLabel";
			this->DescelLabel->Size = System::Drawing::Size(98, 13);
			this->DescelLabel->TabIndex = 57;
			this->DescelLabel->Text = L"Desceleration: 30%";
			this->DescelLabel->Visible = false;
			// 
			// button_Manual
			// 
			this->button_Manual->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_Manual->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Manual->Location = System::Drawing::Point(873, 15);
			this->button_Manual->Name = L"button_Manual";
			this->button_Manual->Size = System::Drawing::Size(104, 47);
			this->button_Manual->TabIndex = 58;
			this->button_Manual->Text = L"Manual";
			this->button_Manual->UseVisualStyleBackColor = true;
			this->button_Manual->Click += gcnew System::EventHandler(this, &MyForm::Manual_click);
			// 
			// button_Move
			// 
			this->button_Move->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_Move->Enabled = false;
			this->button_Move->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Move->Location = System::Drawing::Point(984, 15);
			this->button_Move->Name = L"button_Move";
			this->button_Move->Size = System::Drawing::Size(104, 47);
			this->button_Move->TabIndex = 59;
			this->button_Move->Text = L"Move";
			this->button_Move->UseVisualStyleBackColor = true;
			this->button_Move->Click += gcnew System::EventHandler(this, &MyForm::Move_click);
			// 
			// X_box
			// 
			this->X_box->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->X_box->Enabled = false;
			this->X_box->Location = System::Drawing::Point(724, 389);
			this->X_box->Name = L"X_box";
			this->X_box->Size = System::Drawing::Size(100, 20);
			this->X_box->TabIndex = 60;
			this->X_box->Visible = false;
			// 
			// Y_box
			// 
			this->Y_box->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Y_box->Enabled = false;
			this->Y_box->Location = System::Drawing::Point(724, 415);
			this->Y_box->Name = L"Y_box";
			this->Y_box->Size = System::Drawing::Size(100, 20);
			this->Y_box->TabIndex = 61;
			this->Y_box->Visible = false;
			// 
			// X_label
			// 
			this->X_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->X_label->AutoSize = true;
			this->X_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->X_label->Location = System::Drawing::Point(699, 392);
			this->X_label->Name = L"X_label";
			this->X_label->Size = System::Drawing::Size(19, 13);
			this->X_label->TabIndex = 62;
			this->X_label->Text = L"X:";
			this->X_label->Visible = false;
			// 
			// Y_label
			// 
			this->Y_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Y_label->AutoSize = true;
			this->Y_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Y_label->Location = System::Drawing::Point(699, 418);
			this->Y_label->Name = L"Y_label";
			this->Y_label->Size = System::Drawing::Size(19, 13);
			this->Y_label->TabIndex = 63;
			this->Y_label->Text = L"Y:";
			this->Y_label->Visible = false;
			// 
			// X_go
			// 
			this->X_go->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->X_go->Enabled = false;
			this->X_go->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->X_go->Location = System::Drawing::Point(830, 389);
			this->X_go->Name = L"X_go";
			this->X_go->Size = System::Drawing::Size(33, 23);
			this->X_go->TabIndex = 64;
			this->X_go->Text = L">";
			this->X_go->UseVisualStyleBackColor = true;
			this->X_go->Visible = false;
			this->X_go->Click += gcnew System::EventHandler(this, &MyForm::X_go_Click);
			// 
			// Y_go
			// 
			this->Y_go->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Y_go->Enabled = false;
			this->Y_go->Location = System::Drawing::Point(830, 413);
			this->Y_go->Name = L"Y_go";
			this->Y_go->Size = System::Drawing::Size(33, 23);
			this->Y_go->TabIndex = 65;
			this->Y_go->Text = L">";
			this->Y_go->UseVisualStyleBackColor = true;
			this->Y_go->Visible = false;
			this->Y_go->Click += gcnew System::EventHandler(this, &MyForm::Y_go_Click);
			// 
			// X_stop
			// 
			this->X_stop->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->X_stop->Enabled = false;
			this->X_stop->Location = System::Drawing::Point(869, 389);
			this->X_stop->Name = L"X_stop";
			this->X_stop->Size = System::Drawing::Size(33, 23);
			this->X_stop->TabIndex = 66;
			this->X_stop->Text = L"#";
			this->X_stop->UseVisualStyleBackColor = true;
			this->X_stop->Visible = false;
			// 
			// Y_stop
			// 
			this->Y_stop->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Y_stop->Enabled = false;
			this->Y_stop->Location = System::Drawing::Point(869, 413);
			this->Y_stop->Name = L"Y_stop";
			this->Y_stop->Size = System::Drawing::Size(33, 23);
			this->Y_stop->TabIndex = 67;
			this->Y_stop->Text = L"#";
			this->Y_stop->UseVisualStyleBackColor = true;
			this->Y_stop->Visible = false;
			// 
			// Browse_File
			// 
			this->Browse_File->FileName = L"Browse_File";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1143, 546);
			this->Controls->Add(this->DescelLabel);
			this->Controls->Add(this->Y_stop);
			this->Controls->Add(this->X_stop);
			this->Controls->Add(this->Y_go);
			this->Controls->Add(this->X_go);
			this->Controls->Add(this->Y_label);
			this->Controls->Add(this->X_label);
			this->Controls->Add(this->Y_box);
			this->Controls->Add(this->X_box);
			this->Controls->Add(this->SpeedLabel);
			this->Controls->Add(this->button_Move);
			this->Controls->Add(this->button_Manual);
			this->Controls->Add(this->AccelLabel);
			this->Controls->Add(this->DescelBar);
			this->Controls->Add(this->AccelBar);
			this->Controls->Add(this->button_home);
			this->Controls->Add(this->SpeedBar);
			this->Controls->Add(this->Status);
			this->Controls->Add(this->Z2);
			this->Controls->Add(this->Z1);
			this->Controls->Add(this->A2_rot);
			this->Controls->Add(this->A1_rot);
			this->Controls->Add(this->Y_coord);
			this->Controls->Add(this->X_coord);
			this->Controls->Add(this->Pause);
			this->Controls->Add(this->Step);
			this->Controls->Add(this->Run);
			this->Controls->Add(this->button_xpos);
			this->Controls->Add(this->button_xneg);
			this->Controls->Add(this->button_yneg);
			this->Controls->Add(this->button_ypos);
			this->Controls->Add(this->button_n2dw);
			this->Controls->Add(this->button_n2up);
			this->Controls->Add(this->button_n1dw);
			this->Controls->Add(this->button_n1up);
			this->Controls->Add(this->button_a2_neg);
			this->Controls->Add(this->button_a2_pos);
			this->Controls->Add(this->button_a1_neg);
			this->Controls->Add(this->button_a1_pos);
			this->Controls->Add(this->button_blow2);
			this->Controls->Add(this->button_blow1);
			this->Controls->Add(this->button_vac2);
			this->Controls->Add(this->button_vac1);
			this->Controls->Add(this->button_pick);
			this->Controls->Add(this->button_strip);
			this->Controls->Add(this->button_pump);
			this->Controls->Add(this->Strip);
			this->Controls->Add(this->Pres2);
			this->Controls->Add(this->Pres1);
			this->Controls->Add(this->Blow2);
			this->Controls->Add(this->Blow1);
			this->Controls->Add(this->Vac2);
			this->Controls->Add(this->Vac1);
			this->Controls->Add(this->Pick);
			this->Controls->Add(this->label_ypos);
			this->Controls->Add(this->label_yneg);
			this->Controls->Add(this->label_xpos);
			this->Controls->Add(this->label_xneg);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_speed);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->tbThreshold2);
			this->Controls->Add(this->cbCapture);
			this->Controls->Add(this->tbThreshold);
			this->Controls->Add(this->bLoadFile);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbThreshold))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbThreshold2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SpeedBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccelBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DescelBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bLoadFile_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer2_tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer3_tick(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void button1_click(System::Object^  sender, System::EventArgs^  e);
	//private: System::Void button2_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button_speed_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Pump_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Pick_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Vac1_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Vac2_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Blow1_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Blow2_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Strip_press(System::Object^  sender, System::EventArgs^  e);
	//private: System::Void A1pos_click(System::Object^  sender, System::EventArgs^  e);
	//private: System::Void Vac1_md(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); //MARK
	private: System::Void A1pos_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void A1neg_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void A2pos_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void A2neg_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void N1_up_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void N1_dwn_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void N2_up_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void N2_dwn_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	//private: System::Void A1pos_mouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void A1pos_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void A1neg_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void A2pos_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void A2neg_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void N1_dwn_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void N1_up_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void N2_dwn_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void N2_up_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Xneg_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Xneg_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^e);
	private: System::Void Xpos_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Xpos_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^e);
	private: System::Void Ypos_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Ypos_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^e);
	private: System::Void Yneg_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Yneg_mouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^e);
	private: System::Void SpeedChange(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AccelChange(System::Object^  sender, System::EventArgs^  e);
	private: System::Void DescelChange(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Home_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Move_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Manual_click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void X_go_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Y_go_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
//private: System::Void button1_click(System::Object^  sender, System::EventArgs^  e) { //just created this, may move inside with rest later
//}
//private: System::Void button2_click(System::Object^  sender, System::EventArgs^  e) {
//}
//private: System::Void timer2_tick(System::Object^  sender, System::EventArgs^  e) {
//}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
//private: System::Void Pump_click(System::Object^  sender, System::EventArgs^  e) {
//}


};
};
