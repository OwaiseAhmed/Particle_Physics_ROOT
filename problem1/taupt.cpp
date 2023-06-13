
void taupt()

{

    TH1F *hist_taupt  = new TH1F("tau Pt", "Tau_Pt", 100, 0., 300.);


hist_taupt->GetXaxis()->SetTitle("Tau Pt, Gev/c");

    auto file = TFile::Open("DYJetsToLL.root");

    auto Tree =  (TTree*)file ->Get("Events");

    uint ntau;
    int nentires = Tree->GetEntries();
    int max = 50;

    float tau_pt[max];

    Tree->SetBranchAddress("nTau", &ntau);
    Tree->SetBranchAddress("Tau_pt", tau_pt);

    for (int i = 0; i < nentires; i++)
    {
        Tree->GetEntry(i);
        for (int j = 0; j < ntau; j++)
        {
        if (tau_pt[j]<150){
            hist_taupt->Fill(tau_pt[j]);
            }
        }
    }

    TCanvas *c4 = new TCanvas();
    hist_taupt->Draw();

    return;
}
