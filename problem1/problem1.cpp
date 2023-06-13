void drawHist2()
{

    TH1F *hist_ntau = new TH1F("Histogram for taus", "histogram2", 50, -05, 49.5);

    TFile *file = new TFile("DYJetsToLL.root");

    TTree *t2 = (TTree *)file->Get("Events");

    uint ntau;
    int nentires = t2->GetEntries();

    t2->SetBranchAddress("nTau", &ntau);

    for (int i = 0; i < nentires; i++)
    {

        t2->GetEntry(i);
        hist_ntau->Fill(ntau);
    }

    TCanvas *c2 = new TCanvas();
    hist_ntau->Draw();

    return;
}

void drawHist1()
{

    TH1F *hist_muon = new TH1F("Number of Muons", "hitogram1", 50, -0.5, 49.5);

    TFile *file = new TFile("DYJetsToLL.root");

    TTree *t1 = (TTree *)file->Get("Events");

    uint nMuon;

    int nentires = t1->GetEntries();

    t1->SetBranchAddress("nMuon", &nMuon);

    for (int i = 0; i < nentires; i++)
    {

        t1->GetEntry(i);
        hist_muon->Fill(nMuon);
    }

    TCanvas *c4 = new TCanvas();
    hist_muon->Draw();

    return;
}

void drawHist3()
{

    TH1F *hist_muonpt  = new TH1F("Histogram for muon momentum", "histogram3", 50, -0.5, 49.5);

    auto file = TFile::Open("DYJetsToLL.root");

    TTree1 *t1 =  file ->Get("Events")

    TTree *t3 = file->Get("Events");

    uint nmuon;
    int nentires = t3->GetEntries() int max = 50;

    float Muon_pt[max];

    t1->SetBranchAddress("nMuon", &nmuon);
    t3->SetBranchAddress("Muon_pt", Muon_pt);

    for (int i = 0; i < nentires; i++)
    {
        t3->GetEntry(i);
        for (int j = 0; j < nmuon; j++)
        {

            hist_muonpt->Fill(Muon_pt[j]);
        }
    }

    TCanvas *c3 = new TCanvas();
    hist_muonpt->Draw();

    return;
}


void drawHist4()

{

    TH1F *hist_taupt  = new TH1F("Histogram for tau momentum", "histogram4", 50, -0.5, 49.5);

    auto file = TFile::Open("DYJetsToLL.root");

    TTree1 *t1 =  file ->Get("Events")

    uint ntau;
    int nentires = t4->GetEntries();
    int max = 50;

    float tau_pt[max];

    t1->SetBranchAddress("nTau", &ntau);
    t3->SetBranchAddress("Tau_pt", tau_pt);

    for (int i = 0; i < nentires; i++)
    {
        t4->GetEntry(i);
        for (int j = 0; j < ntaus; j++)
        {

            hist_taupt->Fill(tau_pt[j]);
        }
    }

    TCanvas *c4 = new TCanvas();
    hist_taupt->Draw();

    return;
}





void drawHist5()

{

    TH1F *hist_muonphi  = new TH1F("phi value of muon", "histogram5", 50, -0.5, 49.5);

    auto file = TFile::Open("DYJetsToLL.root");

    TTree1 *t1 =  file ->Get("Events")

    uint nmuon;
    int nentires = t5->GetEntries();
    int max = 50;

    float muon_phi[max];

    t1->SetBranchAddress("nmuon", &nmuon);
    t5->SetBranchAddress("Muon_phi", muon_phi);

    for (int i = 0; i < nentires; i++)
    {
        t5->GetEntry(i);
        for (int j = 0; j < nmuon; j++)
        {

            hist_taupt->Fill(muon_phi[j]);
        }
    }

    TCanvas *c5 = new TCanvas();
    hist_muonphi->Draw();

    return;
}


void problem1()
{

    drawHist1();
    drawHist2();
    drawHist3();

    return;
}
